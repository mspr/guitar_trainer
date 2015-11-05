#include "fretboardeditionscene.h"
#include "fretboardxmlreader.h"
#include "fretboardxmlwriter.h"
#include "fretboardaxis.h"
#include "commandaddaxis.h"
#include "commandremoveaxis.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QUndoStack>
#include <QFile>
#include <QDebug>

using namespace Fretboard;

FretboardEditionScene::FretboardEditionScene(const QString& imagePath, QObject* parent)
	: FretboardScene(parent)
	, m_editionMode(FRET_EDITION)
	, m_editionAxis(nullptr)
	, m_imagePath(imagePath)
	, m_undoStack(new QUndoStack(this))
{
}

void FretboardEditionScene::init(const QPixmap& imagePix,
																 const QHash<uint, double>& yByString,
																 const QHash<uint, double>& xByFret)
{
	addPixmap(imagePix);

	setSceneRect(imagePix.rect().x(),
							 imagePix.rect().y(),
							 imagePix.rect().x() + imagePix.rect().width(),
							 imagePix.rect().y() + imagePix.rect().height());

	QHash<uint, double>::const_iterator it = yByString.begin();
	for (; it != yByString.end(); ++it)
	{
		FretboardAxis* axis = new FretboardAxis(QLineF(0, 0, sceneRect().width(), 0));
		addItem(axis);
		axis->setPos(sceneRect().x(), it.value());
		m_stringAxis.append(axis);
	}

	it = xByFret.begin();
	for (; it != xByFret.end(); ++it)
	{
		FretboardAxis* axis = new FretboardAxis(QLineF(0, 0, 0, sceneRect().height()));
		addItem(axis);
		axis->setPos(it.value(), sceneRect().y());
		m_fretAxis.append(axis);
	}

	switchToSelectionMode();
}

/*static*/ FretboardEditionScene* FretboardEditionScene::tryCreate(const QString& fileName)
{
	FretboardEditionScene* scene = nullptr;

	FretboardXmlReader xmlReader;
	if (xmlReader.handle(fileName))
	{
		QPixmap pix;
		if (pix.load(xmlReader.imagePath()))
		{
			scene = new FretboardEditionScene(xmlReader.imagePath());
			scene->init(pix, xmlReader.yByString(), xmlReader.xByFret());
		}
		else
			qWarning() << QString("Impossible to load fretboard image %1.").arg(xmlReader.imagePath());
	}

	return scene;
}

void FretboardEditionScene::switchToSelectionMode()
{
	if (m_usageMode != SELECTION_MODE)
	{
		if (m_editionAxis != nullptr)
		{
			removeItem(m_editionAxis);
			delete m_editionAxis;
			m_editionAxis = nullptr;
		}

		setAxesMovable(true);

		m_usageMode = SELECTION_MODE;
	}
}

void FretboardEditionScene::setAxesMovable(const bool movable)
{
	foreach (FretboardAxis* fret, m_fretAxis)
		fret->setFlag(QGraphicsItem::ItemIsMovable, movable);
	foreach (FretboardAxis* string, m_stringAxis)
		string->setFlag(QGraphicsItem::ItemIsMovable, movable);
}

void FretboardEditionScene::switchToEditionMode()
{
	if (m_usageMode != EDITION_MODE)
	{
		if (m_editionAxis == nullptr)
		{
			if (m_editionMode == FRET_EDITION)
				m_editionAxis = new FretboardAxis(QLineF(0, 0, 0, sceneRect().height()));
			else // STRING_EDITION
				m_editionAxis = new FretboardAxis(QLineF(0, 0, sceneRect().width(), 0));

			addItem(m_editionAxis);
			m_editionAxis->setPos(sceneRect().x(), sceneRect().y());
			m_editionAxis->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);

			setAxesMovable(false);
		}

		m_usageMode = EDITION_MODE;
	}
}

bool FretboardEditionScene::isInSelectionMode() const
{
	return m_usageMode == SELECTION_MODE;
}

bool FretboardEditionScene::isInFretMode() const
{
	return m_editionMode == FRET_EDITION;
}

bool FretboardEditionScene::isInStringMode() const
{
	return m_editionMode == STRING_EDITION;
}

void FretboardEditionScene::save(const QString& fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QByteArray buffer;
		FretboardXmlWriter writer(&buffer);
		writer.writeStartFretboard(m_imagePath);

		writer.writeStartStrings();
		foreach (const QGraphicsItem* axis, m_stringAxis)
			writer.writeString(axis->y());
		writer.writeEndStrings();

		writer.writeStartFrets();
		foreach (const QGraphicsItem* axis, m_fretAxis)
			writer.writeFret(axis->x());
		writer.writeEndFrets();

		writer.writeEndFretboard();

		file.write(buffer);
		file.close();

		qWarning() << "Scene saved in " << fileName;
	}
}

void FretboardEditionScene::addAxis(FretboardAxis* axis)
{
	Q_ASSERT_X(axis != nullptr, "addAxis()", "nullptr");
	Q_ASSERT_X(m_usageMode == EDITION_MODE, "addAxis()", "The scene is not in edition mode.");

	addItem(axis);

	if (m_editionMode == FRET_EDITION)
		m_fretAxis.append(axis);
	else // STRING_EDITION
		m_stringAxis.append(axis);
}

void FretboardEditionScene::removeAxis(FretboardAxis* axis)
{
	Q_ASSERT_X(axis != nullptr, "removeAxis()", "nullptr");
	Q_ASSERT_X(m_usageMode == EDITION_MODE, "removeAxis()", "The scene is not in edition mode.");

	if (!m_fretAxis.removeOne(axis))
		m_stringAxis.removeOne(axis);

	removeItem(axis);
}

void FretboardEditionScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);

	if (m_usageMode == EDITION_MODE)
		mousePressEdition(event);
	else if (m_usageMode == SELECTION_MODE)
		mousePressSelection(event);
}

void FretboardEditionScene::mousePressEdition(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == EDITION_MODE, "mousePressEdition()", "The scene is not in edition mode.");

	if (event->button() == Qt::RightButton)
	{
		if (m_editionMode == FRET_EDITION)
			switchToStringMode(event->scenePos());
		else // STRING_EDITION
			switchToFretMode(event->scenePos());
	}
	else
	{
		Q_ASSERT_X(m_undoStack != nullptr, "mousePressEdition()", "nullptr");
		m_undoStack->push(new CommandAddAxis(m_editionAxis->scenePos(), m_editionAxis->line(), this));
	}
}

void FretboardEditionScene::mousePressSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == SELECTION_MODE, "mousePressSelection()", "The scene is not in selection mode.");
}

void FretboardEditionScene::switchToFretMode(const QPointF& scenePos)
{
	qWarning() << "switchToFretMode";

	Q_ASSERT_X(m_usageMode == EDITION_MODE, "switchToFretMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != FRET_EDITION, "switchToFretMode()", "The scene is already in fret mode.");
	Q_ASSERT_X(m_editionAxis != nullptr, "switchToFretMode()", "nullptr");

	QPointF p1(scenePos.x(), sceneRect().y());
	m_editionAxis->setPos(p1);
	QPointF p2(0, sceneRect().y() + sceneRect().height());
	m_editionAxis->setLine(QLineF(QPointF(0,0), p2));

	m_editionMode = FRET_EDITION;
}

void FretboardEditionScene::switchToStringMode(const QPointF& scenePos)
{
	qWarning() << "switchToStringMode";

	Q_ASSERT_X(m_usageMode == EDITION_MODE, "switchToStringMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != STRING_EDITION, "switchToStringMode()", "The scene is already in string mode.");
	Q_ASSERT_X(m_editionAxis != nullptr, "switchToStringMode()", "nullptr");

	QPointF p1(sceneRect().x(), scenePos.y());
	m_editionAxis->setPos(p1);
	QPointF p2(sceneRect().x() + sceneRect().width(), 0);
	m_editionAxis->setLine(QLineF(QPointF(0,0), p2));

	m_editionMode = STRING_EDITION;
}

void FretboardEditionScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);

	if (m_usageMode == EDITION_MODE)
		mouseMoveEdition(event);
	else if (m_usageMode == SELECTION_MODE)
		mouseMoveSelection(event);
}

void FretboardEditionScene::mouseMoveEdition(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == EDITION_MODE, "mouseMoveEdition()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionAxis != nullptr, "switchToStringMode()", "nullptr");

	if (m_editionAxis != nullptr)
	{
		if (m_editionMode == FRET_EDITION)
			m_editionAxis->setPos(event->scenePos().x(), sceneRect().y());
		else // STRING_EDITION
			m_editionAxis->setPos(sceneRect().x(), event->scenePos().y());
	}
}

void FretboardEditionScene::mouseMoveSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == SELECTION_MODE, "mouseMoveSelection()", "The scene is not in selection mode.");
}

void FretboardEditionScene::keyPressEvent(QKeyEvent* event)
{
	QGraphicsScene::keyPressEvent(event);

	if (event->key() == Qt::Key_Delete)
	{
		qWarning() << "FretboardEditionScene::keyPressEvent()";
		Q_ASSERT_X(m_undoStack != nullptr, "mousePressEdition()", "nullptr");
		m_undoStack->push(new CommandRemoveAxis(selectedAxes(), this));
	}
}

QList<FretboardAxis*> FretboardEditionScene::selectedAxes() const
{
	QList<FretboardAxis*> selectedAxes;

	foreach (QGraphicsItem* selectedItem, selectedItems())
	{
		FretboardAxis* selectedAxis = qgraphicsitem_cast<FretboardAxis*>(selectedItem);
		Q_ASSERT_X(selectedAxis != nullptr, "selectedAxes()", "nullptr");
		selectedAxes.append(selectedAxis);
	}

	return selectedAxes;
}

#include "fretboardeditionscene.h"
#include "fretboardxmlreader.h"
#include "fretboardxmlwriter.h"
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
	, m_editionMode(EditionMode::FRET)
	, m_axisMarker(new FretboardAxis())
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

void FretboardEditionScene::activateAxisMarker()
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "createAxisMarker()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_axisMarker == nullptr, "createAxisMarker()", "nullptr");

	if (m_editionMode == EditionMode::FRET)
		m_axisMarker->setLine(0, 0, 0, sceneRect().height());
	else // STRING_EDITION
		m_axisMarker->setLine(0, 0, sceneRect().width(), 0);

	m_axisMarker->setFlag(QGraphicsItem::ItemSendsGeometryChanges, false);
	m_axisMarker->setPos(sceneRect().x(), sceneRect().y());

	addItem(m_axisMarker.data());
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
	if (m_usageMode != UsageMode::SELECTION)
	{
		removeItem(m_axisMarker.data());
		setAxesMovable(true);

		m_usageMode = UsageMode::SELECTION;
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
	if (m_usageMode != UsageMode::EDITION)
	{
		if (m_axisMarker == nullptr)
		{
			activateAxisMarker();
			setAxesMovable(false);
		}

		m_usageMode = UsageMode::EDITION;
	}
}

bool FretboardEditionScene::isInSelectionMode() const
{
	return m_usageMode == UsageMode::SELECTION;
}

bool FretboardEditionScene::isInFretMode() const
{
	return m_editionMode == EditionMode::FRET;
}

bool FretboardEditionScene::isInStringMode() const
{
	return m_editionMode == EditionMode::STRING;
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
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "addAxis()", "The scene is not in edition mode.");

	addItem(axis);

	if (m_editionMode == EditionMode::FRET)
		m_fretAxis.append(axis);
	else // EditionMode::STRING
		m_stringAxis.append(axis);
}

void FretboardEditionScene::removeAxis(FretboardAxis* axis)
{
	Q_ASSERT_X(axis != nullptr, "removeAxis()", "nullptr");
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "removeAxis()", "The scene is not in edition mode.");

	if (!m_fretAxis.removeOne(axis))
		m_stringAxis.removeOne(axis);

	removeItem(axis);
}

void FretboardEditionScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);

	if (m_usageMode == UsageMode::EDITION)
		mousePressEdition(event);
	else if (m_usageMode == UsageMode::SELECTION)
		mousePressSelection(event);
}

void FretboardEditionScene::mousePressEdition(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "mousePressEdition()", "The scene is not in edition mode.");

	if (event->button() == Qt::RightButton)
	{
		if (m_editionMode == EditionMode::FRET)
			switchToStringMode(event->scenePos());
		else // EditionMode::STRING
			switchToFretMode(event->scenePos());
	}
	else
	{
		Q_ASSERT_X(m_undoStack != nullptr, "mousePressEdition()", "nullptr");
		m_undoStack->push(new CommandAddAxis(m_axisMarker->scenePos(), m_axisMarker->line(), this));
	}
}

void FretboardEditionScene::mousePressSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::SELECTION, "mousePressSelection()", "The scene is not in selection mode.");
}

void FretboardEditionScene::switchToFretMode(const QPointF& scenePos)
{
	qWarning() << "switchToFretMode";

	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "switchToFretMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != EditionMode::FRET, "switchToFretMode()", "The scene is already in fret mode.");
	Q_ASSERT_X(m_axisMarker != nullptr, "switchToFretMode()", "nullptr");

	QPointF p1(scenePos.x(), sceneRect().y());
	m_axisMarker->setPos(p1);
	QPointF p2(0, sceneRect().y() + sceneRect().height());
	m_axisMarker->setLine(QLineF(QPointF(0,0), p2));

	m_editionMode = EditionMode::FRET;
}

void FretboardEditionScene::switchToStringMode(const QPointF& scenePos)
{
	qWarning() << "switchToStringMode";

	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "switchToStringMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != EditionMode::STRING, "switchToStringMode()", "The scene is already in string mode.");
	Q_ASSERT_X(m_axisMarker != nullptr, "switchToStringMode()", "nullptr");

	QPointF p1(sceneRect().x(), scenePos.y());
	m_axisMarker->setPos(p1);
	QPointF p2(sceneRect().x() + sceneRect().width(), 0);
	m_axisMarker->setLine(QLineF(QPointF(0,0), p2));

	m_editionMode = EditionMode::STRING;
}

void FretboardEditionScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);

	if (m_usageMode == UsageMode::EDITION)
		mouseMoveEdition(event);
	else if (m_usageMode == UsageMode::SELECTION)
		mouseMoveSelection(event);
}

void FretboardEditionScene::mouseMoveEdition(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "mouseMoveEdition()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_axisMarker != nullptr, "switchToStringMode()", "nullptr");

	if (m_axisMarker != nullptr)
	{
		if (m_editionMode == EditionMode::FRET)
			m_axisMarker->setPos(event->scenePos().x(), sceneRect().y());
		else // EditionMode::STRING
			m_axisMarker->setPos(sceneRect().x(), event->scenePos().y());
	}
}

void FretboardEditionScene::mouseMoveSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::SELECTION, "mouseMoveSelection()", "The scene is not in selection mode.");
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

QList<FretboardAxis*> FretboardEditionScene::selectedAxes(const AxisType axisType) const
{
	QList<FretboardAxis*> selectedAxes;

	std::function<bool(FretboardAxis* axis)> isConsideredThroughAxisType;
	switch (axisType)
	{
		case AxisType::FRET:
			isConsideredThroughAxisType = [this](FretboardAxis* axis) -> bool { return m_fretAxis.contains(axis); };
		break;
		case AxisType::STRING:
			isConsideredThroughAxisType = [this](FretboardAxis* axis)->bool { return m_stringAxis.contains(axis); };
		break;
		case AxisType::ALL:
		default:
			isConsideredThroughAxisType = [this](FretboardAxis* axis)->bool { Q_UNUSED(axis); return true; };
		break;
	}

	foreach (QGraphicsItem* selectedItem, selectedItems())
	{
		FretboardAxis* selectedAxis = qgraphicsitem_cast<FretboardAxis*>(selectedItem);
		Q_ASSERT_X(selectedAxis != nullptr, "selectedAxes()", "nullptr");

		if (isConsideredThroughAxisType(selectedAxis))
			selectedAxes.append(selectedAxis);
	}

	return selectedAxes;
}

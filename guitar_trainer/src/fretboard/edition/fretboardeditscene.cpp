#include "fretboardeditscene.h"
#include "fretboard/fretboardxmlreader.h"
#include "fretboard/fretboardxmlwriter.h"
#include "commandremoveaxis.h"
#include "commandaddaxisfret.h"
#include "commandaddaxisstring.h"
#include "fretboardaxisstring.h"
#include "fretboardaxisfret.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QUndoStack>
#include <QFile>
#include <QDebug>

using namespace Fretboard;

FretboardEditScene::FretboardEditScene(const QString& imagePath, QObject* parent)
	: FretboardScene(parent)
	, m_editionMode(EditionMode::FRET)
	, m_axisBuilder(new FretboardAxisBuilder(this))
	, m_imagePath(imagePath)
{
	initCommandStack();
}

FretboardEditScene::~FretboardEditScene()
{
}

void FretboardEditScene::init(const QPixmap& imagePix,
															const QList<Music::Note::ENote>& tuning,
															const QHash<uint, double>& yByString,
															const QHash<uint, double>& xByFret)
{
	FretboardScene::init(imagePix, tuning, yByString, xByFret);

	initAxes();
	switchToSelectionMode();
}

void FretboardEditScene::initCommandStack()
{
	m_undoStack.reset(new QUndoStack(this));
	connect(m_undoStack.data(), SIGNAL(cleanChanged(bool)), SLOT(onCleanChanged(bool)));
}

void FretboardEditScene::onCleanChanged(bool clean)
{
	emit modified(!clean);
}

void FretboardEditScene::initAxes()
{
	QHash<uint, double>::const_iterator it = m_yByString.begin();
	for (; it != m_yByString.end(); ++it)
	{
		FretboardAxisString* string = new FretboardAxisString(QLineF(0, 0, sceneRect().width(), 0));
		addItem(string);
		string->setPos(sceneRect().x(), it.value());
		m_stringAxes.append(string);
	}

	it = m_xByFret.begin();
	for (; it != m_xByFret.end(); ++it)
	{
		FretboardAxisFret* fret = new FretboardAxisFret(QLineF(0, 0, 0, sceneRect().height()));
		addItem(fret);
		fret->setPos(it.value(), sceneRect().y());
		m_fretAxes.append(fret);
	}
}

/*static*/ FretboardEditScene* FretboardEditScene::tryCreate(const QString& fileName)
{
	FretboardEditScene* scene = nullptr;

	FretboardXmlReader xmlReader;
	if (xmlReader.handle(fileName))
	{
		QPixmap pix;
		if (pix.load(xmlReader.imagePath()))
		{
			scene = new FretboardEditScene(xmlReader.imagePath());
			scene->init(pix, xmlReader.tuning(), xmlReader.yByString(), xmlReader.xByFret());
		}
		else
			qWarning() << QString("Impossible to load fretboard image %1.").arg(xmlReader.imagePath());
	}

	return scene;
}

void FretboardEditScene::switchToSelectionMode()
{
	if (m_usageMode != UsageMode::SELECTION)
	{
		m_usageMode = UsageMode::SELECTION;
		m_axisBuilder->deactivate();
		setAxesMovable(true);
	}
}

void FretboardEditScene::setAxesMovable(const bool movable)
{
	foreach (FretboardAxisFret* fret, m_fretAxes)
		fret->setFlag(QGraphicsItem::ItemIsMovable, movable);
	foreach (FretboardAxisString* string, m_stringAxes)
		string->setFlag(QGraphicsItem::ItemIsMovable, movable);
}

void FretboardEditScene::switchToEditionMode()
{
	if (m_usageMode != UsageMode::EDITION)
	{
		m_usageMode = UsageMode::EDITION;

		m_axisBuilder->activate();
		setAxesMovable(false);
	}
}

FretboardEditScene::EditionMode FretboardEditScene::editionMode() const
{
	return m_editionMode;
}

bool FretboardEditScene::isInSelectionMode() const
{
	return m_usageMode == UsageMode::SELECTION;
}

bool FretboardEditScene::isInFretMode() const
{
	return m_editionMode == EditionMode::FRET;
}

bool FretboardEditScene::isInStringMode() const
{
	return m_editionMode == EditionMode::STRING;
}

void FretboardEditScene::save(const QString& fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QByteArray buffer;
		FretboardXmlWriter writer(&buffer);
		writer.writeStartFretboard(m_imagePath);

		writer.writeStartStrings();
		foreach (const QGraphicsItem* axis, m_stringAxes)
			writer.writeString(axis->y());
		writer.writeEndStrings();

		writer.writeStartFrets();
		foreach (const QGraphicsItem* axis, m_fretAxes)
			writer.writeFret(axis->x());
		writer.writeEndFrets();

		writer.writeEndFretboard();

		file.write(buffer);
		file.close();

		qWarning() << "Scene saved in " << fileName;
	}
}

void FretboardEditScene::addFret(FretboardAxisFret* fret)
{
	Q_ASSERT_X(fret != nullptr, "addFret()", "nullptr");

	addItem(fret);
	m_fretAxes.append(fret);
}

void FretboardEditScene::addString(FretboardAxisString* string)
{
	Q_ASSERT_X(string != nullptr, "addString()", "nullptr");

	addItem(string);
	m_stringAxes.append(string);
}

void FretboardEditScene::removeFret(FretboardAxisFret* fret)
{
	Q_ASSERT_X(fret != nullptr, "removeFret()", "nullptr");

	m_fretAxes.removeOne(fret);
	removeItem(fret);
}

void FretboardEditScene::removeString(FretboardAxisString* string)
{
	Q_ASSERT_X(string != nullptr, "removeString()", "nullptr");

	m_stringAxes.removeOne(string);
	removeItem(string);
}

void FretboardEditScene::clear()
{
	FretboardScene::clear();
	clearAxes();
}

void FretboardEditScene::clearAxes()
{
	qDeleteAll(m_fretAxes);
	m_fretAxes.clear();
	qDeleteAll(m_stringAxes);
	m_stringAxes.clear();
}

void FretboardEditScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);

	if (m_usageMode == UsageMode::EDITION)
		mousePressEdition(event);
	else if (m_usageMode == UsageMode::SELECTION)
		mousePressSelection(event);
}

void FretboardEditScene::mousePressEdition(QGraphicsSceneMouseEvent* event)
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
		if (m_editionMode == FretboardEditScene::EditionMode::FRET)
			m_undoStack->push(new CommandAddAxisFret(m_axisBuilder.data(), this));
		else if (m_editionMode == FretboardEditScene::EditionMode::STRING)
			m_undoStack->push(new CommandAddAxisString(m_axisBuilder.data(), this));
	}
}

void FretboardEditScene::mousePressSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::SELECTION, "mousePressSelection()", "The scene is not in selection mode.");
}

void FretboardEditScene::switchToFretMode(const QPointF& scenePos)
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "switchToFretMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != EditionMode::FRET, "switchToFretMode()", "The scene is already in fret mode.");

	m_axisBuilder->switchToFretMode(scenePos);
	m_editionMode = EditionMode::FRET;
}

void FretboardEditScene::switchToStringMode(const QPointF& scenePos)
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "switchToStringMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != EditionMode::STRING, "switchToStringMode()", "The scene is already in string mode.");

	m_axisBuilder->switchToStringMode(scenePos);
	m_editionMode = EditionMode::STRING;
}

void FretboardEditScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);

	if (m_usageMode == UsageMode::EDITION)
		m_axisBuilder->move(event->scenePos());
}

void FretboardEditScene::keyPressEvent(QKeyEvent* event)
{
	QGraphicsScene::keyPressEvent(event);

	if (event->modifiers().testFlag(Qt::ControlModifier))
	{
		if (event->key() == Qt::Key_Z)
			m_undoStack->undo();
		else if (event->key() == Qt::Key_Y)
			m_undoStack->redo();
		else if (event->key() == Qt::Key_Z)
			m_undoStack->clear();
	}
	else if (event->key() == Qt::Key_Delete)
	{
		m_undoStack->push(new CommandRemoveAxis(selectedFrets(), selectedStrings(), this));
	}
}

template <typename T>
QList<T*> FretboardEditScene::selectedAxes() const
{
	QList<T*> selectedAxes;

	foreach (QGraphicsItem* selectedItem, selectedItems())
	{
		T* selectedAxis = qgraphicsitem_cast<T*>(selectedItem);
		if (selectedAxis != nullptr)
			selectedAxes.append(selectedAxis);
	}

	return selectedAxes;
}

QList<FretboardAxisFret*> FretboardEditScene::selectedFrets() const
{
	return selectedAxes<FretboardAxisFret>();
}

QList<FretboardAxisString*> FretboardEditScene::selectedStrings() const
{
	return selectedAxes<FretboardAxisString>();
}

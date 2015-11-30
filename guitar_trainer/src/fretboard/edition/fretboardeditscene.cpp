#include "fretboardeditscene.h"
#include "fretboardaxiseditable.h"
#include "fretboard/fretboardxmlreader.h"
#include "fretboard/fretboardxmlwriter.h"
#include "commandaddaxis.h"
#include "commandremoveaxis.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QUndoStack>
#include <QFile>
#include <QDebug>

using namespace Fretboard;

FretboardEditScene::FretboardEditScene(const QString& imagePath, QObject* parent)
	: FretboardScene(parent)
	, m_editionMode(EditionMode::FRET)
	, m_axisEditor(new FretboardAxisEditor())
	, m_imagePath(imagePath)
	, m_undoStack(new QUndoStack(this))
{
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

void FretboardEditScene::initAxes()
{
	QHash<uint, double>::const_iterator it = m_yByString.begin();
	for (; it != m_yByString.end(); ++it)
	{
		FretboardAxisEditable* axis = new FretboardAxisEditable(QLineF(0, 0, sceneRect().width(), 0));
		addItem(axis);
		qWarning() << "string pos " << QPointF(sceneRect().x(), it.value());
		axis->setPos(sceneRect().x(), it.value());
		m_stringAxes.append(axis);
	}

	it = m_xByFret.begin();
	for (; it != m_xByFret.end(); ++it)
	{
		FretboardAxisEditable* axis = new FretboardAxisEditable(QLineF(0, 0, 0, sceneRect().height()));
		addItem(axis);
		qWarning() << "fret pos " << QPointF(it.value(), sceneRect().y());
		axis->setPos(it.value(), sceneRect().y());
		m_fretAxes.append(axis);
	}
}

void FretboardEditScene::activateAxisEditor()
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "activateAxisEditor()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_axisEditor.data() != nullptr, "activateAxisEditor()", "nullptr");

	if (m_editionMode == EditionMode::FRET)
		m_axisEditor->setLine(0, 0, 0, sceneRect().height());
	else // STRING_EDITION
		m_axisEditor->setLine(0, 0, sceneRect().width(), 0);

	m_axisEditor->setPos(sceneRect().x(), sceneRect().y());

	addItem(m_axisEditor.data());
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

		if (items().contains(m_axisEditor.data()))
			removeItem(m_axisEditor.data());

		setAxesMovable(true);
	}
}

void FretboardEditScene::setAxesMovable(const bool movable)
{
	foreach (FretboardAxisEditable* fret, m_fretAxes)
		fret->setFlag(QGraphicsItem::ItemIsMovable, movable);
	foreach (FretboardAxisEditable* string, m_stringAxes)
		string->setFlag(QGraphicsItem::ItemIsMovable, movable);
}

void FretboardEditScene::switchToEditionMode()
{
	if (m_usageMode != UsageMode::EDITION)
	{
		m_usageMode = UsageMode::EDITION;

		activateAxisEditor();
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

void FretboardEditScene::addFret(FretboardAxisEditable* fret)
{
	Q_ASSERT_X(fret != nullptr, "addFret()", "nullptr");

	addItem(fret);
	m_fretAxes.append(fret);
}

void FretboardEditScene::addString(FretboardAxisEditable* string)
{
	Q_ASSERT_X(string != nullptr, "addString()", "nullptr");

	addItem(string);
	m_stringAxes.append(string);
}

void FretboardEditScene::removeAxis(FretboardAxisEditable* axis)
{
	Q_ASSERT_X(axis != nullptr, "removeAxis()", "nullptr");

	if (!m_fretAxes.removeOne(axis))
		m_stringAxes.removeOne(axis);

	removeItem(axis);
}

void FretboardEditScene::removeFret(FretboardAxisEditable* fret)
{
	Q_ASSERT_X(fret != nullptr, "removeFret()", "nullptr");

	m_fretAxes.removeOne(fret);
	removeItem(fret);
}

void FretboardEditScene::removeString(FretboardAxisEditable* string)
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
		Q_ASSERT_X(m_undoStack != nullptr, "mousePressEdition()", "nullptr");
		m_undoStack->push(new CommandAddAxis(m_axisEditor->scenePos(), m_axisEditor->line(), this));
	}
}

void FretboardEditScene::mousePressSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::SELECTION, "mousePressSelection()", "The scene is not in selection mode.");
}

void FretboardEditScene::switchToFretMode(const QPointF& scenePos)
{
	qWarning() << "switchToFretMode";

	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "switchToFretMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != EditionMode::FRET, "switchToFretMode()", "The scene is already in fret mode.");
	Q_ASSERT_X(m_axisEditor != nullptr, "switchToFretMode()", "nullptr");

	QPointF p1(scenePos.x(), sceneRect().y());
	m_axisEditor->setPos(p1);
	QPointF p2(0, sceneRect().y() + sceneRect().height());
	m_axisEditor->setLine(QLineF(QPointF(0,0), p2));

	m_editionMode = EditionMode::FRET;
}

void FretboardEditScene::switchToStringMode(const QPointF& scenePos)
{
	qWarning() << "switchToStringMode";

	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "switchToStringMode()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_editionMode != EditionMode::STRING, "switchToStringMode()", "The scene is already in string mode.");
	Q_ASSERT_X(m_axisEditor != nullptr, "switchToStringMode()", "nullptr");

	QPointF p1(sceneRect().x(), scenePos.y());
	m_axisEditor->setPos(p1);
	QPointF p2(sceneRect().x() + sceneRect().width(), 0);
	m_axisEditor->setLine(QLineF(QPointF(0,0), p2));

	m_editionMode = EditionMode::STRING;
}

void FretboardEditScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);

	if (m_usageMode == UsageMode::EDITION)
		mouseMoveEdition(event);
	else if (m_usageMode == UsageMode::SELECTION)
		mouseMoveSelection(event);
}

void FretboardEditScene::mouseMoveEdition(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::EDITION, "mouseMoveEdition()", "The scene is not in edition mode.");
	Q_ASSERT_X(m_axisEditor != nullptr, "switchToStringMode()", "nullptr");

	if (m_axisEditor != nullptr)
	{
		if (m_editionMode == EditionMode::FRET)
			m_axisEditor->setPos(event->scenePos().x(), sceneRect().y());
		else // EditionMode::STRING
			m_axisEditor->setPos(sceneRect().x(), event->scenePos().y());
	}
}

void FretboardEditScene::mouseMoveSelection(QGraphicsSceneMouseEvent* event)
{
	Q_ASSERT_X(m_usageMode == UsageMode::SELECTION, "mouseMoveSelection()", "The scene is not in selection mode.");
}

void FretboardEditScene::keyPressEvent(QKeyEvent* event)
{
	QGraphicsScene::keyPressEvent(event);

	if (event->key() == Qt::Key_Delete)
	{
		qWarning() << "FretboardEditionScene::keyPressEvent()";
		Q_ASSERT_X(m_undoStack != nullptr, "mousePressEdition()", "nullptr");
		m_undoStack->push(new CommandRemoveAxis(selectedFrets(), selectedStrings(), this));
	}
}

QList<FretboardAxisEditable*> FretboardEditScene::selectedAxes() const
{
	return selectedAxes(AxisType::ALL);
}

QList<FretboardAxisEditable*> FretboardEditScene::selectedFrets() const
{
	return selectedAxes(AxisType::FRET);
}

QList<FretboardAxisEditable*> FretboardEditScene::selectedStrings() const
{
	return selectedAxes(AxisType::STRING);
}

QList<FretboardAxisEditable*> FretboardEditScene::selectedAxes(const AxisType axisType) const
{
	QList<FretboardAxisEditable*> selectedAxes;

	std::function<bool(FretboardAxisEditable* axis)> isConsideredThroughAxisType;
	switch (axisType)
	{
		case AxisType::FRET:
			isConsideredThroughAxisType = [this](FretboardAxisEditable* axis) -> bool { return m_fretAxes.contains(axis); };
		break;
		case AxisType::STRING:
			isConsideredThroughAxisType = [this](FretboardAxisEditable* axis)->bool { return m_stringAxes.contains(axis); };
		break;
		case AxisType::ALL:
		default:
			isConsideredThroughAxisType = [this](FretboardAxisEditable* axis)->bool { Q_UNUSED(axis); return true; };
		break;
	}

	foreach (QGraphicsItem* selectedItem, selectedItems())
	{
		FretboardAxisEditable* selectedAxis = qgraphicsitem_cast<FretboardAxisEditable*>(selectedItem);
		Q_ASSERT_X(selectedAxis != nullptr, "selectedAxes()", "nullptr");

		if (isConsideredThroughAxisType(selectedAxis))
			selectedAxes.append(selectedAxis);
	}

	return selectedAxes;
}

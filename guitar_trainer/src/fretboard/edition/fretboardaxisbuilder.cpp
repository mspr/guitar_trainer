#include "fretboardaxisbuilder.h"
#include "fretboardeditscene.h"
#include "fretboardaxisstring.h"
#include "fretboardaxisfret.h"

using namespace Fretboard;

FretboardAxisBuilder::FretboardAxisBuilder(FretboardEditScene* scene)
	: m_scene(scene)
{
	Q_ASSERT_X(m_scene != nullptr, "FretboardAxisBuilder()", "nullptr");

	initMarkers();
}

void FretboardAxisBuilder::initMarkers()
{
	m_fretMarker.reset(new FretboardAxisFret());
	m_stringMarker.reset(new FretboardAxisString());
}

void FretboardAxisBuilder::activate()
{
	if (m_scene->isInFretMode())
	{
		m_fretMarker->setLine(0, 0, 0, m_scene->sceneRect().height());
		m_fretMarker->setPos(m_scene->sceneRect().x(), m_scene->sceneRect().y());
		m_scene->addItem(m_fretMarker.data());
	}
	else // in string mode
	{
		m_stringMarker->setLine(0, 0, m_scene->sceneRect().width(), 0);
		m_stringMarker->setPos(m_scene->sceneRect().x(), m_scene->sceneRect().y());
		m_scene->addItem(m_stringMarker.data());
	}
}

void FretboardAxisBuilder::deactivate()
{
	if (m_scene->items().contains(m_fretMarker.data()))
		m_scene->removeItem(m_fretMarker.data());
	if (m_scene->items().contains(m_stringMarker.data()))
		m_scene->removeItem(m_stringMarker.data());
}

void FretboardAxisBuilder::move(const QPointF& scenePos)
{
	if (m_scene->isInFretMode())
		m_fretMarker->setPos(scenePos.x(), m_scene->sceneRect().y());
	else // in string mode
		m_stringMarker->setPos(m_scene->sceneRect().x(), scenePos.y());
}

void FretboardAxisBuilder::switchToFretMode(const QPointF& scenePos)
{
	m_scene->removeItem(m_stringMarker.data());

	QPointF p1(scenePos.x(), m_scene->sceneRect().y());
	m_fretMarker->setPos(p1);
	QPointF p2(0, m_scene->sceneRect().y() + m_scene->sceneRect().height());
	m_fretMarker->setLine(QLineF(QPointF(0,0), p2));
	m_scene->addItem(m_fretMarker.data());
}

void FretboardAxisBuilder::switchToStringMode(const QPointF& scenePos)
{
	m_scene->removeItem(m_fretMarker.data());

	QPointF p1(m_scene->sceneRect().x(), scenePos.y());
	m_stringMarker->setPos(p1);
	QPointF p2(m_scene->sceneRect().x() + m_scene->sceneRect().width(), 0);
	m_stringMarker->setLine(QLineF(QPointF(0,0), p2));
	m_scene->addItem(m_stringMarker.data());
}

FretboardAxisFret* FretboardAxisBuilder::buildFretFromMarker() const
{
	FretboardAxisFret* fret = new FretboardAxisFret(m_fretMarker.data()->line(), m_fretMarker.data()->parentItem());
	fret->setPos(m_fretMarker->scenePos());
	fret->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemIsSelectable);
	fret->setAcceptHoverEvents(true);

	return fret;
}

FretboardAxisFret* FretboardAxisBuilder::buildFret(const QLineF& line, const QPointF& scenePos) const
{
	FretboardAxisFret* fret = new FretboardAxisFret(line);
	fret->setPos(scenePos);
	fret->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemIsSelectable);
	fret->setAcceptHoverEvents(true);

	return fret;
}

FretboardAxisString* FretboardAxisBuilder::buildStringFromMarker() const
{
	FretboardAxisString* string = new FretboardAxisString(m_stringMarker.data()->line(), m_stringMarker.data()->parentItem());
	string->setPos(m_stringMarker->scenePos());
	string->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemIsSelectable);
	string->setAcceptHoverEvents(true);

	return string;
}

FretboardAxisString* FretboardAxisBuilder::buildString(const QLineF& line, const QPointF& scenePos) const
{
	FretboardAxisString* string = new FretboardAxisString(line);
	string->setPos(scenePos);
	string->setFlags(QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemSendsGeometryChanges | QGraphicsItem::ItemIsSelectable);
	string->setAcceptHoverEvents(true);

	return string;
}

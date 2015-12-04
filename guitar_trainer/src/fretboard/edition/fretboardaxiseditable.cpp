#include "fretboardaxiseditable.h"
#include "fretboardeditscene.h"

#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QDebug>

using namespace Fretboard;

FretboardAxisEditable::FretboardAxisEditable(QGraphicsItem* parent)
	: FretboardAxis(parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
	setFlags(ItemIsFocusable | ItemSendsGeometryChanges | ItemIsSelectable);
	setAcceptHoverEvents(true);
}

FretboardAxisEditable::FretboardAxisEditable(const QLineF& line, QGraphicsItem* parent)
	: FretboardAxis(line, parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
	setFlags(ItemIsFocusable | ItemSendsGeometryChanges | ItemIsSelectable);
	setAcceptHoverEvents(true);
}

void FretboardAxisEditable::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	QApplication::setOverrideCursor(Qt::PointingHandCursor);
	FretboardAxis::hoverEnterEvent(event);
}

void FretboardAxisEditable::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	QApplication::restoreOverrideCursor();
	FretboardAxis::hoverLeaveEvent(event);
}

void FretboardAxisEditable::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (getScene()->isInSelectionMode())
	{
		if (event->buttons() & Qt::LeftButton)
			QApplication::setOverrideCursor(Qt::ClosedHandCursor);
	}

	FretboardAxis::mousePressEvent(event);
}

void FretboardAxisEditable::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if (getScene()->isInSelectionMode())
		QApplication::restoreOverrideCursor();

	FretboardAxis::mouseReleaseEvent(event);
}

QVariant FretboardAxisEditable::itemChange(GraphicsItemChange change, const QVariant& value)
{
	qWarning() << "itemChange " << change;

	if (change == ItemSelectedChange)
	{
		const QColor penColor = (value.toBool() ? m_selectionColor : m_defaultColor);
		QPen pen = this->pen();
		pen.setColor(penColor);
		setPen(pen);
	}
	else if (change == ItemSceneHasChanged)
	{
		QGraphicsScene* scene = value.value<QGraphicsScene*>();
		if (scene == nullptr)
			QApplication::restoreOverrideCursor();
	}

	return FretboardAxis::itemChange(change, value);
}

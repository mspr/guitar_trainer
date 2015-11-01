#include "fretboardaxis.h"

#include <QApplication>
#include <QPen>
#include <QDebug>

using namespace Fretboard;

FretboardAxis::FretboardAxis(const QLineF& line, QGraphicsItem* parent)
	: QGraphicsLineItem(line, parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
	setFlag(ItemIsFocusable);
	setAcceptHoverEvents(true);
}

void FretboardAxis::focusInEvent(QFocusEvent* event)
{
	qWarning() << "FretboardAxis::focusInEvent";
	QPen pen = this->pen();
	pen.setColor(m_selectionColor);
	setPen(pen);

	QGraphicsLineItem::focusInEvent(event);
}

void FretboardAxis::focusOutEvent(QFocusEvent* event)
{
	qWarning() << "FretboardAxis::focusOutEvent";

	QPen pen = this->pen();
	pen.setColor(m_defaultColor);
	setPen(pen);

	QGraphicsLineItem::focusOutEvent(event);
}

void FretboardAxis::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	qWarning() << "FretboardAxis::hoverEnterEvent";

	QApplication::setOverrideCursor(Qt::PointingHandCursor);

	QGraphicsLineItem::hoverEnterEvent(event);
}

void FretboardAxis::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	qWarning() << "FretboardAxis::hoverLeaveEvent";

	QApplication::restoreOverrideCursor();

	QGraphicsLineItem::hoverLeaveEvent(event);
}

void FretboardAxis::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	qWarning() << "FretboardAxis::mousePressEvent";

	QGraphicsLineItem::mousePressEvent(event);
}

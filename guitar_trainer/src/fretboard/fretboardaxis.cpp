#include "fretboardaxis.h"
#include "fretboardeditionscene.h"

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

FretboardEditionScene* FretboardAxis::getScene() const
{
	FretboardEditionScene* scene = dynamic_cast<FretboardEditionScene*>(this->scene());
	Q_ASSERT_X(scene != nullptr, "mousePressEvent()", "nullptr");
	return scene;
}

void FretboardAxis::focusInEvent(QFocusEvent* event)
{
	QPen pen = this->pen();
	pen.setColor(m_selectionColor);
	setPen(pen);

	QGraphicsLineItem::focusInEvent(event);
}

void FretboardAxis::focusOutEvent(QFocusEvent* event)
{
	QPen pen = this->pen();
	pen.setColor(m_defaultColor);
	setPen(pen);

	QGraphicsLineItem::focusOutEvent(event);
}

void FretboardAxis::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	QApplication::setOverrideCursor(Qt::PointingHandCursor);

	QGraphicsLineItem::hoverEnterEvent(event);
}

void FretboardAxis::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	QApplication::restoreOverrideCursor();

	QGraphicsLineItem::hoverLeaveEvent(event);
}

void FretboardAxis::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	qWarning() << "FretboardAxis::mousePressEvent";

	if (getScene()->isInSelectionMode())
		QApplication::setOverrideCursor(Qt::ClosedHandCursor);

	QGraphicsLineItem::mousePressEvent(event);
}

void FretboardAxis::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	qWarning() << "FretboardAxis::mouseReleaseEvent";

	if (getScene()->isInSelectionMode())
		QApplication::setOverrideCursor(Qt::PointingHandCursor);

	QGraphicsLineItem::mouseReleaseEvent(event);
}

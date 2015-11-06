#include "fretboardaxis.h"
#include "fretboardeditionscene.h"

#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QDebug>

using namespace Fretboard;

FretboardAxis::FretboardAxis(QGraphicsItem* parent)
	: QGraphicsLineItem(parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
	setFlags(ItemIsFocusable | ItemSendsGeometryChanges);
	setAcceptHoverEvents(true);
}

FretboardAxis::FretboardAxis(const QLineF& line, QGraphicsItem* parent)
	: QGraphicsLineItem(line, parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
	setFlags(ItemIsFocusable | ItemSendsGeometryChanges);
	setAcceptHoverEvents(true);
}

FretboardEditionScene* FretboardAxis::getScene() const
{
	FretboardEditionScene* scene = dynamic_cast<FretboardEditionScene*>(this->scene());
	Q_ASSERT_X(scene != nullptr, "getScene()", "nullptr");
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
	{
		if (event->buttons() & Qt::LeftButton)
			QApplication::setOverrideCursor(Qt::ClosedHandCursor);
	}

	QGraphicsLineItem::mousePressEvent(event);
}

void FretboardAxis::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	qWarning() << "FretboardAxis::mouseReleaseEvent";

	if (getScene()->isInSelectionMode())
		QApplication::setOverrideCursor(Qt::PointingHandCursor);

	QGraphicsLineItem::mouseReleaseEvent(event);
}

QVariant FretboardAxis::itemChange(GraphicsItemChange change, const QVariant& value)
{
	if (change == ItemPositionChange)
	{
		QPointF newPos = value.toPointF();

		FretboardEditionScene* scene = getScene();
		if (scene->isInFretMode())
			newPos.setY(scenePos().y());
		else if (scene->isInStringMode())
			newPos.setX(scenePos().x());

		return newPos;
	}

	return QGraphicsLineItem::itemChange(change, value);
}

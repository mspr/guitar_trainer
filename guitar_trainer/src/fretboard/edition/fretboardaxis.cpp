#include "fretboardaxis.h"
#include "fretboardeditscene.h"

#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

using namespace Fretboard;

FretboardAxis::FretboardAxis(QGraphicsItem* parent)
	: QGraphicsLineItem(parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
}

FretboardAxis::FretboardAxis(const QLineF& line, QGraphicsItem* parent)
	: QGraphicsLineItem(line, parent)
	, m_defaultColor(Qt::cyan)
	, m_selectionColor(Qt::red)
{
	setPen(QPen(m_defaultColor, 4));
}

FretboardEditScene* FretboardAxis::getScene() const
{
	FretboardEditScene* scene = qobject_cast<FretboardEditScene*>(this->scene());
	Q_ASSERT_X(scene != nullptr, "getScene()", "nullptr");
	return scene;
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
	if (getScene()->isInSelectionMode())
	{
		if (event->buttons() & Qt::LeftButton)
			QApplication::setOverrideCursor(Qt::ClosedHandCursor);
	}

	QGraphicsLineItem::mousePressEvent(event);
}

void FretboardAxis::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if (getScene()->isInSelectionMode())
		QApplication::restoreOverrideCursor();

	QGraphicsLineItem::mouseReleaseEvent(event);
}

QVariant FretboardAxis::itemChange(GraphicsItemChange change, const QVariant& value)
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

	return QGraphicsLineItem::itemChange(change, value);
}

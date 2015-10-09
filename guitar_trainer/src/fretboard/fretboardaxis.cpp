#include "fretboardaxis.h"

#include <QPen>

using namespace Fretboard;

FretboardAxis::FretboardAxis(const QPointF& scenePos, const QLineF& line, QGraphicsItem* parent)
	: QGraphicsLineItem(line, parent)
{
	setPen(QPen(Qt::cyan, 4));
	setPos(scenePos);
}

FretboardAxis::FretboardAxis(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem* parent)
	: QGraphicsLineItem(x1, y1, x2, y2, parent)
{
	setPen(QPen(Qt::cyan, 4));
}

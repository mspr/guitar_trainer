#include "fretboardaxis.h"

using namespace Fretboard;

FretboardAxis::FretboardAxis(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem* parent)
	: QGraphicsLineItem(x1, y1, x2, y2, parent)
{
}

#include "fretboardaxis.h"

#include <QPen>

using namespace Fretboard;

FretboardAxis::FretboardAxis(const QLineF& line, QGraphicsItem* parent)
	: QGraphicsLineItem(line, parent)
{
	setPen(QPen(Qt::cyan, 4));
}

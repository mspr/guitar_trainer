#include "fretboardaxisfret.h"

using namespace Fretboard;

FretboardAxisFret::FretboardAxisFret(QGraphicsItem* parent)
	: FretboardAxis(parent)
{
}

FretboardAxisFret::FretboardAxisFret(const QLineF& line, QGraphicsItem* parent)
	: FretboardAxis(line, parent)
{
}

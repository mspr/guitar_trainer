#include "fretboardaxisfret.h"

using namespace Fretboard;

FretboardAxisFret::FretboardAxisFret(QGraphicsItem* parent)
	: FretboardAxisEditable(parent)
{
}

FretboardAxisFret::FretboardAxisFret(const QLineF& line, QGraphicsItem* parent)
	: FretboardAxisEditable(line, parent)
{
}

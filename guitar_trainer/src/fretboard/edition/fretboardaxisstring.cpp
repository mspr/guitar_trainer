#include "fretboardaxisstring.h"

using namespace Fretboard;

FretboardAxisString::FretboardAxisString(QGraphicsItem* parent)
	: FretboardAxis(parent)
{
}

FretboardAxisString::FretboardAxisString(const QLineF& line, QGraphicsItem* parent)
	: FretboardAxis(line, parent)
{
}

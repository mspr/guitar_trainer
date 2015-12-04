#include "fretboardaxisstring.h"

using namespace Fretboard;

FretboardAxisString::FretboardAxisString(QGraphicsItem* parent)
	: FretboardAxisEditable(parent)
{
}

FretboardAxisString::FretboardAxisString(const QLineF& line, QGraphicsItem* parent)
	: FretboardAxisEditable(line, parent)
{
}

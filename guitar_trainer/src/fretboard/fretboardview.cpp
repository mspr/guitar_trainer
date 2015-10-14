#include "fretboardview.h"

using namespace Fretboard;

FretboardView::FretboardView(QWidget* parent)
	: QGraphicsView(parent)
{
	setAcceptDrops(true);
}

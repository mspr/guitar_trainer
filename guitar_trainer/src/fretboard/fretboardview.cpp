#include "fretboardview.h"

using namespace Fretboard;

FretboardView::FretboardView(QWidget* parent)
	: QGraphicsView(parent)
{
	setMouseTracking(true);
	setAcceptDrops(true);
}

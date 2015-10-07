#include "freatboardnote.h"

using namespace Fretboard;
using namespace Music;

FreatboardNote::FreatboardNote(Note::ENote note, QGraphicsItem* parent)
	: QGraphicsEllipseItem(parent)
	, m_note(note)
{
}

#include "fretboardnote.h"

using namespace Fretboard;
using namespace Music;

FretboardNote::FretboardNote(Note::ENote note, QGraphicsItem* parent)
	: QGraphicsEllipseItem(parent)
	, m_note(note)
{
}

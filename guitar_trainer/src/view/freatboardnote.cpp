#include "freatboardnote.h"

using namespace View;

FreatboardNote::FreatboardNote(Model::Note::ENote note, QGraphicsItem* parent)
	: QGraphicsEllipseItem(parent)
	, m_note(note)
{
}

#ifndef FREATBOARDNOTE_H
#define FREATBOARDNOTE_H

#include <QGraphicsEllipseItem>

#include "music/note.h"

namespace Fretboard
{
	class FreatboardNote : public QGraphicsEllipseItem
	{
		public:
			FreatboardNote(Music::Note::ENote note, QGraphicsItem* parent);

		private:
			Music::Note::ENote m_note;
	};

} // Fretboard

#endif // FREATBOARDNOTE_H

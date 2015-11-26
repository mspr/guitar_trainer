#ifndef FRETBOARDNOTE_H
#define FRETBOARDNOTE_H

#include <QGraphicsEllipseItem>

#include "music/note.h"

namespace Fretboard
{
	class FretboardNote : public QGraphicsEllipseItem
	{
		public:
			FretboardNote(Music::Note::ENote note, QGraphicsItem* parent = 0);

		private:
			Music::Note::ENote m_note;
	};

} // Fretboard

#endif // FRETBOARDNOTE_H

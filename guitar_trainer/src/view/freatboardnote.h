#ifndef FREATBOARDNOTE_H
#define FREATBOARDNOTE_H

#include <QGraphicsEllipseItem>

#include "model/note.h"

namespace View
{
	class FreatboardNote : public QGraphicsEllipseItem
	{
		public:
			FreatboardNote(Model::Note::ENote note, QGraphicsItem* parent);

		private:
			Model::Note::ENote m_note;
	};

} // View

#endif // FREATBOARDNOTE_H

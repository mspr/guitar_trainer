#ifndef COMMANDADDAXIS_H
#define COMMANDADDAXIS_H

#include "fretboardeditscene.h"

#include <QUndoCommand>
#include <QLineF>

namespace Fretboard
{
	class CommandAddAxis : public QUndoCommand
	{
		public:
			CommandAddAxis(const QPointF& scenePos,
										 const QLineF& line,
										 FretboardEditScene* scene);

		protected:
			FretboardEditScene* m_scene;
			QPointF m_scenePos;
			QLineF m_line;
	};

} // Fretboard

#endif // COMMANDADDAXIS_H

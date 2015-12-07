#ifndef COMMANDADDAXIS_H
#define COMMANDADDAXIS_H

#include "fretboardeditscene.h"

#include <QUndoCommand>

namespace Fretboard
{
	class FretboardAxisBuilder;

	class CommandAddAxis : public QUndoCommand
	{
		public:
			CommandAddAxis(const FretboardAxisBuilder* axisBuilder,
										 FretboardEditScene* scene);

		protected:
			FretboardEditScene* m_scene;
			const FretboardAxisBuilder* m_axisBuilder;
			QPointF m_scenePos;
			QLineF m_line;
	};

} // Fretboard

#endif // COMMANDADDAXIS_H

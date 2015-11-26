#ifndef COMMANDADDAXIS_H
#define COMMANDADDAXIS_H

#include "fretboardeditscene.h"

#include <QUndoCommand>
#include <QLineF>

namespace Fretboard
{
	class FretboardAxis;

	class CommandAddAxis : public QUndoCommand
	{
		public:
			CommandAddAxis(const QPointF& scenePos,
										 const QLineF& line,
										 FretboardEditScene* scene);

			virtual void undo() override;
			virtual void redo() override;

		private:
			FretboardEditScene* m_scene;
			FretboardEditScene::EditionMode m_editionMode;
			FretboardAxis* m_axis;
			QPointF m_scenePos;
			QLineF m_line;
	};

} // Fretboard

#endif // COMMANDADDAXIS_H

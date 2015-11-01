#ifndef COMMANDMOVEAXIS_H
#define COMMANDMOVEAXIS_H

#include <QUndoCommand>
#include <QPointF>

namespace Fretboard
{
	class FretboardAxis;

	class CommandMoveAxis : public QUndoCommand
	{
		public:
			CommandMoveAxis(FretboardAxis* axis, const QPointF& oldScenePos);

			virtual void undo() override;
			virtual void redo() override;
			virtual bool mergeWith(const QUndoCommand* command) override;

		private:
			FretboardAxis* m_axis;
			QPointF m_oldScenePos;
			QPointF m_newScenePos;
	};

} // Fretboard

#endif // COMMANDMOVEAXIS_H

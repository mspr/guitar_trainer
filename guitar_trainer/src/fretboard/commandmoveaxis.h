#ifndef COMMANDMOVEAXIS_H
#define COMMANDMOVEAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class CommandMoveAxis : public QUndoCommand
	{
		public:
			CommandMoveAxis();

			virtual void undo() override;
			virtual void redo() override;
	};

} // Fretboard

#endif // COMMANDMOVEAXIS_H

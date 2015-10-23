#ifndef COMMANDMOVEAXIS_H
#define COMMANDMOVEAXIS_H

#include <QUndoCommand>

class CommandMoveAxis : public QUndoCommand
{
	public:
		CommandMoveAxis();

		virtual void undo() override;
		virtual void redo() override;
};

#endif // COMMANDMOVEAXIS_H

#ifndef COMMANDREMOVEAXIS_H
#define COMMANDREMOVEAXIS_H

#include <QUndoCommand>

class CommandRemoveAxis : public QUndoCommand
{
	public:
		CommandRemoveAxis();

		virtual void undo() override;
		virtual void redo() override;
};

#endif // COMMANDREMOVEAXIS_H

#ifndef COMMANDADDAXIS_H
#define COMMANDADDAXIS_H

#include <QUndoCommand>

class CommandAddAxis : public QUndoCommand
{
	public:
		CommandAddAxis();

		virtual void undo() override;
		virtual void redo() override;
};

#endif // COMMANDADDAXIS_H

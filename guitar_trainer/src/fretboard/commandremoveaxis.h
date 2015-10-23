#ifndef COMMANDREMOVEAXIS_H
#define COMMANDREMOVEAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class CommandRemoveAxis : public QUndoCommand
	{
		public:
			CommandRemoveAxis();

			virtual void undo() override;
			virtual void redo() override;
	};

} // Fretboard

#endif // COMMANDREMOVEAXIS_H

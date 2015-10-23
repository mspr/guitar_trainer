#ifndef COMMANDADDAXIS_H
#define COMMANDADDAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class CommandAddAxis : public QUndoCommand
	{
		public:
			CommandAddAxis();

			virtual void undo() override;
			virtual void redo() override;
	};

} // Fretboard

#endif // COMMANDADDAXIS_H

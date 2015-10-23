#ifndef COMMANDREMOVEAXIS_H
#define COMMANDREMOVEAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class FretboardEditionScene;

	class CommandRemoveAxis : public QUndoCommand
	{
		public:
			CommandRemoveAxis(FretboardEditionScene* scene);

			virtual void undo() override;
			virtual void redo() override;

		private:
			FretboardEditionScene* m_scene;
	};

} // Fretboard

#endif // COMMANDREMOVEAXIS_H

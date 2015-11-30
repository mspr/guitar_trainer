#ifndef COMMANDREMOVEAXIS_H
#define COMMANDREMOVEAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class FretboardEditScene;
	class FretboardAxisEditable;

	class CommandRemoveAxis : public QUndoCommand
	{
		public:
			CommandRemoveAxis(const QList<FretboardAxisEditable*>& selectedFrets,
												const QList<FretboardAxisEditable*>& selectedStrings,
												FretboardEditScene* scene);
			~CommandRemoveAxis();

			virtual void undo() override;
			virtual void redo() override;

		private:
			FretboardEditScene* m_scene;
			QList<FretboardAxisEditable*> m_fretsToRemove;
			QList<FretboardAxisEditable*> m_stringsToRemove;
	};

} // Fretboard

#endif // COMMANDREMOVEAXIS_H

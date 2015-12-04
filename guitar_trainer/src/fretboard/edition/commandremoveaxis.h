#ifndef COMMANDREMOVEAXIS_H
#define COMMANDREMOVEAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class FretboardEditScene;
	class FretboardAxisEditable;
	class FretboardAxisFret;
	class FretboardAxisString;

	class CommandRemoveAxis : public QUndoCommand
	{
		public:
			CommandRemoveAxis(const QList<FretboardAxisFret*>& selectedFrets,
												const QList<FretboardAxisString*>& selectedStrings,
												FretboardEditScene* scene);
			~CommandRemoveAxis();

			virtual void undo() override;
			virtual void redo() override;

		private:
			FretboardEditScene* m_scene;
			QList<FretboardAxisFret*> m_fretsToRemove;
			QList<FretboardAxisString*> m_stringsToRemove;
			QList<FretboardAxisEditable*> m_axesToDelete;
	};

} // Fretboard

#endif // COMMANDREMOVEAXIS_H

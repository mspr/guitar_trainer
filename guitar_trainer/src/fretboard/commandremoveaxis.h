#ifndef COMMANDREMOVEAXIS_H
#define COMMANDREMOVEAXIS_H

#include <QUndoCommand>

namespace Fretboard
{
	class FretboardEditionScene;
	class FretboardAxis;

	class CommandRemoveAxis : public QUndoCommand
	{
		public:
			CommandRemoveAxis(const QList<FretboardAxis*>& selectedFrets,
												const QList<FretboardAxis*>& selectedStrings,
												FretboardEditionScene* scene);
			~CommandRemoveAxis();

			virtual void undo() override;
			virtual void redo() override;

		private:
			FretboardEditionScene* m_scene;
			QList<FretboardAxis*> m_fretsToRemove;
			QList<FretboardAxis*> m_stringsToRemove;
	};

} // Fretboard

#endif // COMMANDREMOVEAXIS_H

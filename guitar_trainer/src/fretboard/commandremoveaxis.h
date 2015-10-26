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
			CommandRemoveAxis(const QList<FretboardAxis*>& selectedAxes, FretboardEditionScene* scene);

			virtual void undo() override;
			virtual void redo() override;

		private:
			FretboardEditionScene* m_scene;
			QList<FretboardAxis*> m_selectedAxes;
	};

} // Fretboard

#endif // COMMANDREMOVEAXIS_H

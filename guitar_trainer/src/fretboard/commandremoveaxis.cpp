#include "commandremoveaxis.h"
#include "fretboardeditionscene.h"

using namespace Fretboard;

CommandRemoveAxis::CommandRemoveAxis(const QList<FretboardAxis*>& selectedAxes, FretboardEditionScene* scene)
	: m_scene(scene)
	, m_selectedAxes(selectedAxes)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandRemoveAxis()", "nullptr");

	QList<QGraphicsItem*> selectedItems = scene->selectedItems();
}

void CommandRemoveAxis::undo()
{

}

void CommandRemoveAxis::redo()
{
}

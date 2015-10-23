#include "commandremoveaxis.h"

using namespace Fretboard;

CommandRemoveAxis::CommandRemoveAxis(FretboardEditionScene* scene)
	: m_scene(scene)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandRemoveAxis()", "nullptr");
}

void CommandRemoveAxis::undo()
{

}

void CommandRemoveAxis::redo()
{
}

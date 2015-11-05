#include "commandremoveaxis.h"
#include "fretboardeditionscene.h"

using namespace Fretboard;

CommandRemoveAxis::CommandRemoveAxis(const QList<FretboardAxis*>& selectedAxes, FretboardEditionScene* scene)
	: m_scene(scene)
	, m_selectedAxes(selectedAxes)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandRemoveAxis()", "nullptr");
}

void CommandRemoveAxis::undo()
{
	/*
	foreach (FretboardAxis* axis, m_selectedAxes)
		m_scene->addAxis(axis); // TODO frets or strings ?
		*/
}

void CommandRemoveAxis::redo()
{
	foreach (FretboardAxis* axis, m_selectedAxes)
		m_scene->removeAxis(axis); // TODO Delete axes somewhere is needed..
}

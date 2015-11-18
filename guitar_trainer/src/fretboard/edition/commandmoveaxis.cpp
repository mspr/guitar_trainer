#include "commandmoveaxis.h"
#include "fretboardaxis.h"

using namespace Fretboard;

CommandMoveAxis::CommandMoveAxis(FretboardAxis* axis, const QPointF& oldScenePos)
	:	m_axis(axis)
	, m_oldScenePos(oldScenePos)
	, m_newScenePos(axis->scenePos())
{
}

void CommandMoveAxis::undo()
{
	m_axis->setPos(m_oldScenePos);
}

void CommandMoveAxis::redo()
{
	m_axis->setPos(m_newScenePos);
}

bool CommandMoveAxis::mergeWith(const QUndoCommand* command)
{
	const CommandMoveAxis* moveCommand = static_cast<const CommandMoveAxis*>(command);
	FretboardAxis* axis = moveCommand->m_axis;

	if (m_axis != axis)
		return false;

	m_newScenePos = axis->scenePos();

	return true;
}

#include "commandaddaxis.h"
#include "fretboardeditscene.h"

using namespace Fretboard;

CommandAddAxis::CommandAddAxis(const QPointF& scenePos,
															 const QLineF& line,
															 FretboardEditScene* scene)
	: m_scene(scene)
	, m_scenePos(scenePos)
	, m_line(line)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandAddAxis()", "nullptr");
}

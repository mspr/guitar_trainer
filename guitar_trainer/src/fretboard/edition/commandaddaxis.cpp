#include "commandaddaxis.h"
#include "fretboardeditscene.h"

using namespace Fretboard;

CommandAddAxis::CommandAddAxis(const FretboardAxisBuilder* axisBuilder,
															 FretboardEditScene* scene)
	: m_scene(scene)
	, m_axisBuilder(axisBuilder)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandAddAxis()", "nullptr");
	Q_ASSERT_X(m_axisBuilder != nullptr, "CommandAddAxis()", "nullptr");
}

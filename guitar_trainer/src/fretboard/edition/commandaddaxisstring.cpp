#include "commandaddaxisstring.h"
#include "fretboardaxisstring.h"

using namespace Fretboard;

CommandAddAxisString::CommandAddAxisString(const QPointF& scenePos,
																					 const QLineF& line,
																					 FretboardEditScene* scene)
	: CommandAddAxis(scenePos, line, scene)
	, m_string(nullptr)
{
	QString commandMsg = "Add string : pos (%1, %2) | line [p1(%3, %4), p2(%5, %6)]";
	commandMsg.arg(scenePos.x()).arg(scenePos.y());
	commandMsg.arg(line.p1().x()).arg(line.p1().y());
	commandMsg.arg(line.p2().x()).arg(line.p2().y());
	setText(commandMsg);
}

void CommandAddAxisString::undo()
{
	m_scene->removeString(m_string);
	delete m_string;
	m_string = nullptr;
}

void CommandAddAxisString::redo()
{
	Q_ASSERT_X(m_string == nullptr, "redo()", "nullptr");

	m_string = new FretboardAxisString(m_line);
	m_scene->addString(m_string);
	m_string->setPos(m_scenePos);
}

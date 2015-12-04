#include "commandaddaxisfret.h"
#include "fretboardaxisfret.h"

using namespace Fretboard;

CommandAddAxisFret::CommandAddAxisFret(const QPointF& scenePos,
																			 const QLineF& line,
																			 FretboardEditScene* scene)
	: CommandAddAxis(scenePos, line, scene)
	, m_fret(nullptr)
{
	QString commandMsg = "Add fret : pos (%1, %2) | line [p1(%3, %4), p2(%5, %6)]";
	commandMsg.arg(scenePos.x()).arg(scenePos.y());
	commandMsg.arg(line.p1().x()).arg(line.p1().y());
	commandMsg.arg(line.p2().x()).arg(line.p2().y());
	setText(commandMsg);
}

void CommandAddAxisFret::undo()
{
	m_scene->removeFret(m_fret);
	delete m_fret;
	m_fret = nullptr;
}

void CommandAddAxisFret::redo()
{
	Q_ASSERT_X(m_fret == nullptr, "redo()", "nullptr");

	m_fret = new FretboardAxisFret(m_line);
	m_scene->addFret(m_fret);
	m_fret->setPos(m_scenePos);
}

#include "commandaddaxis.h"
#include "fretboardeditionscene.h"
#include "fretboardaxis.h"

using namespace Fretboard;

CommandAddAxis::CommandAddAxis(const QPointF& scenePos,
															 const QLineF& line,
															 FretboardEditionScene* scene)
	: m_scene(scene)
	, m_axis(nullptr)
	, m_scenePos(scenePos)
	, m_line(line)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandAddAxis()", "nullptr");

	m_editionMode = m_scene->editionMode();

	QString commandMsg = "Add axis : pos (%1, %2) | line [p1(%3, %4), p2(%5, %6)]";
	commandMsg.arg(scenePos.x()).arg(scenePos.y());
	commandMsg.arg(line.p1().x()).arg(line.p1().y());
	commandMsg.arg(line.p2().x()).arg(line.p2().y());
	setText(commandMsg);
}

void CommandAddAxis::undo()
{
	m_scene->removeAxis(m_axis);
	delete m_axis;
	m_axis = nullptr;
}

void CommandAddAxis::redo()
{
	Q_ASSERT_X(m_axis == nullptr, "redo()", "nullptr");

	m_axis = new FretboardAxis(m_line);

	if (m_editionMode == FretboardEditionScene::EditionMode::FRET)
		m_scene->addFret(m_axis);
	else if (m_editionMode == FretboardEditionScene::EditionMode::STRING)
		m_scene->addString(m_axis);

	m_axis->setPos(m_scenePos);
}

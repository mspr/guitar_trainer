#include "commandremoveaxis.h"
#include "fretboardeditscene.h"

using namespace Fretboard;

CommandRemoveAxis::CommandRemoveAxis(const QList<FretboardAxis*>& selectedFrets,
																		 const QList<FretboardAxis*>& selectedStrings,
																		 FretboardEditScene* scene)
	: m_scene(scene)
	, m_fretsToRemove(selectedFrets)
	, m_stringsToRemove(selectedStrings)
{
	Q_ASSERT_X(m_scene != nullptr, "CommandRemoveAxis()", "nullptr");
}

CommandRemoveAxis::~CommandRemoveAxis()
{
	// TODO don't delete axes if undo has been called
	qDeleteAll(m_fretsToRemove);
	m_fretsToRemove.clear();
	qDeleteAll(m_stringsToRemove);
	m_stringsToRemove.clear();
}

void CommandRemoveAxis::undo()
{
	foreach (FretboardAxis* fret, m_fretsToRemove)
		m_scene->addFret(fret);
	foreach (FretboardAxis* string, m_stringsToRemove)
		m_scene->addString(string);
}

void CommandRemoveAxis::redo()
{
	foreach (FretboardAxis* fret, m_fretsToRemove)
		m_scene->removeFret(fret);
	foreach (FretboardAxis* string, m_stringsToRemove)
		m_scene->removeString(string);
}

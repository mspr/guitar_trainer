#include "commandremoveaxis.h"
#include "fretboardeditscene.h"
#include "fretboardaxiseditable.h"

using namespace Fretboard;

CommandRemoveAxis::CommandRemoveAxis(const QList<FretboardAxisEditable*>& selectedFrets,
																		 const QList<FretboardAxisEditable*>& selectedStrings,
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
	foreach (FretboardAxisEditable* fret, m_fretsToRemove)
		m_scene->addFret(fret);
	foreach (FretboardAxisEditable* string, m_stringsToRemove)
		m_scene->addString(string);
}

void CommandRemoveAxis::redo()
{
	foreach (FretboardAxisEditable* fret, m_fretsToRemove)
		m_scene->removeFret(fret);
	foreach (FretboardAxisEditable* string, m_stringsToRemove)
		m_scene->removeString(string);
}

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
	qDeleteAll(m_axesToDelete);
	m_fretsToRemove.clear();
	m_stringsToRemove.clear();
}

void CommandRemoveAxis::undo()
{
	foreach (FretboardAxisEditable* fret, m_fretsToRemove)
		m_scene->addFret(fret);
	foreach (FretboardAxisEditable* string, m_stringsToRemove)
		m_scene->addString(string);

	m_axesToDelete.clear();
}

void CommandRemoveAxis::redo()
{
	foreach (FretboardAxisEditable* fret, m_fretsToRemove)
		m_scene->removeFret(fret);
	foreach (FretboardAxisEditable* string, m_stringsToRemove)
		m_scene->removeString(string);

	m_axesToDelete.append(m_fretsToRemove);
	m_axesToDelete.append(m_stringsToRemove);
}

#include "commandremoveaxis.h"
#include "fretboardeditscene.h"
#include "fretboardaxisstring.h"
#include "fretboardaxisfret.h"

using namespace Fretboard;

CommandRemoveAxis::CommandRemoveAxis(const QList<FretboardAxisFret*>& selectedFrets,
																		 const QList<FretboardAxisString*>& selectedStrings,
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
	foreach (FretboardAxisFret* fret, m_fretsToRemove)
		m_scene->addFret(fret);
	foreach (FretboardAxisString* string, m_stringsToRemove)
		m_scene->addString(string);

	m_axesToDelete.clear();
}

void CommandRemoveAxis::redo()
{
	foreach (FretboardAxisFret* fret, m_fretsToRemove)
	{
		m_scene->removeFret(fret);
		m_axesToDelete.append(fret);
	}
	foreach (FretboardAxisString* string, m_stringsToRemove)
	{
		m_scene->removeString(string);
		m_axesToDelete.append(string);
	}
}

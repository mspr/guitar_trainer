#include "fretboardscenebuilder.h"
#include "fretboardxmlreader.h"

using namespace Fretboard;

FretboardSceneBuilder::FretboardSceneBuilder()
	: m_fretboardXmlReader(new FretboardXmlReader())
{
}

FretboardSceneBuilder::~FretboardSceneBuilder()
{
}

bool FretboardSceneBuilder::load(const QString& fileName)
{
	bool loaded = false;

	if (m_fretboardXmlReader->handle(fileName))
		loaded = m_pix.load(m_fretboardXmlReader->imagePath());

	return loaded;
}

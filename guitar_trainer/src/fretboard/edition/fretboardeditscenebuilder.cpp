#include "fretboardeditscenebuilder.h"
#include "fretboard/fretboardxmlreader.h"

using namespace Fretboard;

FretboardEditSceneBuilder::FretboardEditSceneBuilder()
	: FretboardSceneBuilder()
{
}

FretboardEditScene* FretboardEditSceneBuilder::tryCreateScene(const QString& fileName)
{
	FretboardEditScene* scene = nullptr;

	if (load(fileName))
	{
		scene = new FretboardEditScene(m_fretboardXmlReader->imagePath());

		scene->init(m_pix,
								m_fretboardXmlReader->tuning(),
								m_fretboardXmlReader->yByString(),
								m_fretboardXmlReader->xByFret());
	}

	return scene;
}

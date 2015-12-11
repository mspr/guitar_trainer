#include "fretboardplayscenebuilder.h"
#include "fretboard/fretboardxmlreader.h"

using namespace Fretboard;

FretboardPlaySceneBuilder::FretboardPlaySceneBuilder()
{
}

FretboardPlayScene* FretboardPlaySceneBuilder::tryCreateScene(const QString& fileName)
{
	FretboardPlayScene* scene = nullptr;

	if (load(fileName))
	{
		scene = new FretboardPlayScene();

		scene->init(m_pix,
								m_fretboardXmlReader->tuning(),
								m_fretboardXmlReader->yByString(),
								m_fretboardXmlReader->xByFret());
	}

	return scene;
}

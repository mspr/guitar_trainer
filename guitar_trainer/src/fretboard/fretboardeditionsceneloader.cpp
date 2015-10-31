#include "fretboardeditionsceneloader.h"
#include "fretboardeditionscene.h"

#include <QFileDialog>

using namespace Fretboard;

/*static*/ FretboardEditionScene* FretboardEditionSceneLoader::tryCreateSceneFromOpenFile()
{
	const QString fileName = QFileDialog::getOpenFileName(nullptr,
																												QObject::tr("Open File"),
																												"",
																												QObject::tr("Xml Files (*.xml);;Images (*.png *.jpg)"));

	return tryCreateSceneFromFile(fileName);
}

/*static*/ FretboardEditionScene* FretboardEditionSceneLoader::tryCreateSceneFromFile(const QString& fileName)
{
	FretboardEditionScene* scene = nullptr;

	if (!fileName.isNull())
		scene = FretboardEditionScene::tryLoad(fileName);

	return scene;
}

/*static*/ bool FretboardEditionSceneLoader::isSupported(const QString& fileName)
{
	return isImage(fileName) || QFileInfo(fileName).suffix() == "xml";
}

/*static*/ bool FretboardEditionSceneLoader::isImage(const QString& fileName)
{
	return QFileInfo(fileName).suffix() == "png" || QFileInfo(fileName).suffix() == "jpg";
}

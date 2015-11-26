#include "fretboardeditsceneloader.h"
#include "fretboardeditscene.h"

#include <QFileDialog>

using namespace Fretboard;

/*static*/ FretboardEditScene* FretboardEditSceneLoader::tryCreateSceneFromOpenFile()
{
	const QString fileName = QFileDialog::getOpenFileName(nullptr,
																												QObject::tr("Open File"),
																												"",
																												QObject::tr("Xml Files (*.xml);;Images (*.png *.jpg)"));

	return tryCreateSceneFromFile(fileName);
}

/*static*/ FretboardEditScene* FretboardEditSceneLoader::tryCreateSceneFromFile(const QString& fileName)
{
	FretboardEditScene* scene = nullptr;

	if (!fileName.isNull())
		scene = FretboardEditScene::tryCreate(fileName);

	return scene;
}

/*static*/ bool FretboardEditSceneLoader::isSupported(const QString& fileName)
{
	return isImage(fileName) || QFileInfo(fileName).suffix() == "xml";
}

/*static*/ bool FretboardEditSceneLoader::isImage(const QString& fileName)
{
	return QFileInfo(fileName).suffix() == "png" || QFileInfo(fileName).suffix() == "jpg";
}

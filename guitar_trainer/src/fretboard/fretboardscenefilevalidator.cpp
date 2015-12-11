#include "fretboardscenefilevalidator.h"

#include <QFileDialog>

using namespace Fretboard;

/*static*/ QString FretboardSceneFileValidator::getOpenFileName()
{
	return QFileDialog::getOpenFileName(nullptr,
																			QObject::tr("Open File"),
																			"",
																			QObject::tr("Xml Files (*.xml);;Images (*.png *.jpg)"));

}

/*static*/ bool FretboardSceneFileValidator::isSupported(const QString& fileName)
{
	return isImage(fileName) || QFileInfo(fileName).suffix() == "xml";
}

/*static*/ bool FretboardSceneFileValidator::isImage(const QString& fileName)
{
	return QFileInfo(fileName).suffix() == "png" || QFileInfo(fileName).suffix() == "jpg";
}

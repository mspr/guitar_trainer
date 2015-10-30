#include "fretboardeditionsceneloader.h"
#include "fretboardeditionwindow.h"
#include "fretboardeditionscene.h"

#include <QFileDialog>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

using namespace Fretboard;

FretboardEditionSceneLoader::FretboardEditionSceneLoader(FretboardEditionWindow& fretboardEditionWindow)
{
	fretboardEditionWindow.installEventFilter(this);
}

FretboardEditionScene* FretboardEditionSceneLoader::tryCreateSceneFromOpenFile()
{
	const QString fileName = QFileDialog::getOpenFileName(nullptr,
																												QObject::tr("Open File"),
																												"",
																												QObject::tr("Xml Files (*.xml);;Images (*.png *.jpg)"));

	return tryCreateSceneFromFile(fileName);
}

FretboardEditionScene* FretboardEditionSceneLoader::tryCreateSceneFromFile(const QString& fileName)
{
	FretboardEditionScene* scene = nullptr;

	if (!fileName.isNull())
		scene = FretboardEditionScene::tryLoad(fileName);

	return scene;
}

bool FretboardEditionSceneLoader::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::DragEnter)
	{
		QDragEnterEvent* dragEnterEvt = static_cast<QDragEnterEvent*>(event);
		const QString fileName = dragEnterEvt->mimeData()->urls().first().toLocalFile();
		if (isSupported(fileName))
			dragEnterEvt->acceptProposedAction();
	}
	else if (event->type() == QEvent::Drop)
	{
		QDropEvent* dropEvt = static_cast<QDropEvent*>(event);
		const QString fileName = dropEvt->mimeData()->urls().first().toLocalFile();
		if (isSupported(fileName))
			dropEvt->acceptProposedAction();
	}

	return QObject::eventFilter(object, event);
}

bool FretboardEditionSceneLoader::isSupported(const QString& fileName)
{
	return isImage(fileName) || QFileInfo(fileName).suffix() == "xml";
}

bool FretboardEditionSceneLoader::isImage(const QString& fileName)
{
	return QFileInfo(fileName).suffix() == "png" || QFileInfo(fileName).suffix() == "jpg";
}

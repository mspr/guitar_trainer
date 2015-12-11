#include "fretboardwindow.h"
#include "fretboardscenefilevalidator.h"
#include "fretboardscenebuilder.h"

#include <QDragMoveEvent>
#include <QMimeData>

using namespace Fretboard;

FretboardWindow::FretboardWindow(QWidget* parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
}

FretboardWindow::~FretboardWindow()
{
}

void FretboardWindow::open()
{
	const QString fileName = FretboardSceneFileValidator::getOpenFileName();
	//tryCreateScene(fileName);
}

void FretboardWindow::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->urls().count() == 1)
	{
		const QString fileName = event->mimeData()->urls().first().toLocalFile();
		if (FretboardSceneFileValidator::isSupported(fileName))
			event->acceptProposedAction();
	}

	QMainWindow::dragEnterEvent(event);
}

void FretboardWindow::dropEvent(QDropEvent* event)
{
	Q_ASSERT_X(event->mimeData()->urls().count() == 1, "dropEvent()", "");

	const QString fileName = event->mimeData()->urls().first().toLocalFile();
	//tryCreateScene(fileName);

	QMainWindow::dropEvent(event);
}

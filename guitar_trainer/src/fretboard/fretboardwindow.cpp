#include "fretboardwindow.h"
#include "fretboardscenefilevalidator.h"
#include "fretboardscenebuilder.h"

#include <QGraphicsView>
#include <QDragMoveEvent>
#include <QMimeData>
#include <QDebug>

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
	tryCreateScene(fileName);
}

bool FretboardWindow::tryCreateScene(const QString& fileName)
{
	bool created = false;

	Q_ASSERT_X(m_sceneBuilder != nullptr, "tryCreateScene()", "nullptr");
	FretboardScene* scene = m_sceneBuilder->tryCreateScene(fileName);
	if (scene != nullptr)
	{
		m_scene.reset(scene);
		initScene();
		created = true;
	}
	else
		qWarning() << "Impossible to create scene from file " << fileName;

	return created;
}

void FretboardWindow::initScene()
{
	Q_ASSERT_X(m_scene != nullptr, "initScene()", "nullptr");

	QGraphicsView* view = qobject_cast<QGraphicsView*>(centralWidget());
	Q_ASSERT_X(view != nullptr, "initScene()", "nullptr");

	view->setScene(m_scene.data());
	view->setMouseTracking(true);
	//m_scene->setFocus();

	initScene_impl();
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
	tryCreateScene(fileName);

	QMainWindow::dropEvent(event);
}

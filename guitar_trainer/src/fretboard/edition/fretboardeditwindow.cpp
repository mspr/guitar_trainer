#include "fretboardeditwindow.h"
#include "ui_fretboardeditwindow.h"
#include "fretboardeditview.h"
#include "fretboardeditscene.h"
#include "fretboardeditsceneloader.h"

#include <QFileDialog>
#include <QKeyEvent>
#include <QDragMoveEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QDebug>

using namespace Fretboard;

FretboardEditWindow::FretboardEditWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::FretboardEditWindow)
{
	m_ui->setupUi(this);

	setWindowTitle("MainWindow [*]");

	FretboardEditView* fretboardView = new FretboardEditView(this);
	setCentralWidget(fretboardView);

	setAcceptDrops(true);

	m_ui->editionAct->setDisabled(true);
	m_ui->selectionAct->setDisabled(true);
}

FretboardEditWindow::~FretboardEditWindow()
{
	delete m_ui;
}

FretboardEditView* FretboardEditWindow::editionView() const
{
	FretboardEditView* fretboardView = qobject_cast<FretboardEditView*>(centralWidget());
	Q_ASSERT_X(fretboardView != nullptr, "editionView()", "nullptr");
	return fretboardView;
}

void FretboardEditWindow::open()
{
	m_scene = FretboardEditSceneLoader::tryCreateSceneFromOpenFile();
	if (m_scene != nullptr)
		initScene();
}

void FretboardEditWindow::initScene()
{
	Q_ASSERT_X(m_scene != nullptr, "onSceneCreation()", "nullptr");

	m_scene->setParent(this);
	connect(m_scene, SIGNAL(modified(bool)), SLOT(setWindowModified(bool)));
	editionView()->setScene(m_scene);
	editionView()->setMouseTracking(true);
	//m_scene->setFocus();

	m_ui->editionAct->setEnabled(true);
	m_ui->selectionAct->setEnabled(true);
}

void FretboardEditWindow::save()
{
	const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
	{
		if (m_scene != nullptr)
			m_scene->save(fileName);
	}
}

void FretboardEditWindow::switchToSelectionMode()
{
	if (m_scene != nullptr)
	{
		m_scene->switchToSelectionMode();

		m_ui->selectionAct->setDisabled(true);
		m_ui->editionAct->setEnabled(true);
	}
}

void FretboardEditWindow::switchToEditionMode()
{
	if (m_scene != nullptr)
	{
		m_scene->switchToEditionMode();

		m_ui->editionAct->setDisabled(true);
		m_ui->selectionAct->setEnabled(true);
	}
}

void FretboardEditWindow::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->urls().count() == 1)
	{
		const QString fileName = event->mimeData()->urls().first().toLocalFile();
		if (FretboardEditSceneLoader::isSupported(fileName))
			event->acceptProposedAction();
	}

	QMainWindow::dragEnterEvent(event);
}

void FretboardEditWindow::dropEvent(QDropEvent* event)
{
	Q_ASSERT_X(event->mimeData()->urls().count() == 1, "dropEvent()", "");

	const QString fileName = event->mimeData()->urls().first().toLocalFile();
	m_scene = FretboardEditSceneLoader::tryCreateSceneFromFile(fileName);
	if (m_scene != nullptr)
		initScene();

	QMainWindow::dropEvent(event);
}

void FretboardEditWindow::keyPressEvent(QKeyEvent* event)
{
	QMainWindow::keyPressEvent(event);

	if (event->key() == Qt::Key_Escape)
		close();
}

void FretboardEditWindow::closeEvent(QCloseEvent* event)
{
	/*
	const QMessageBox::StandardButton reply = QMessageBox::question(this,
																																	"The edition window is about to close.",
																																	"Do you want to save changes ?",
																																	QMessageBox::Yes|QMessageBox::No);

	if (reply == QMessageBox::Yes)
		save();
		*/

	QMainWindow::closeEvent(event);
}

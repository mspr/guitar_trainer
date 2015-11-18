#include "fretboardeditionwindow.h"
#include "ui_fretboardeditionwindow.h"
#include "fretboardeditionview.h"
#include "fretboardeditionscene.h"
#include "fretboardeditionsceneloader.h"

#include <QFileDialog>
#include <QKeyEvent>
#include <QDragMoveEvent>
#include <QMimeData>
#include <QMessageBox>
#include <QDebug>

using namespace Fretboard;

FretboardEditionWindow::FretboardEditionWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::FretboardEditionWindow)
{
	m_ui->setupUi(this);

	FretboardEditionView* fretboardView = new FretboardEditionView(this);
	setCentralWidget(fretboardView);

	setAcceptDrops(true);

	m_ui->editionAct->setDisabled(true);
	m_ui->selectionAct->setDisabled(true);
}

FretboardEditionWindow::~FretboardEditionWindow()
{
	delete m_ui;
}

FretboardEditionView* FretboardEditionWindow::editionView() const
{
	FretboardEditionView* fretboardView = qobject_cast<FretboardEditionView*>(centralWidget());
	Q_ASSERT_X(fretboardView != nullptr, "editionView()", "nullptr");
	return fretboardView;
}

void FretboardEditionWindow::open()
{
	m_scene = FretboardEditionSceneLoader::tryCreateSceneFromOpenFile();
	if (m_scene != nullptr)
		initScene();
}

void FretboardEditionWindow::initScene()
{
	Q_ASSERT_X(m_scene != nullptr, "onSceneCreation()", "nullptr");

	m_scene->setParent(this);
	editionView()->setScene(m_scene);
	editionView()->setMouseTracking(true);
	//m_scene->setFocus();

	m_ui->editionAct->setEnabled(true);
	m_ui->selectionAct->setEnabled(true);
}

void FretboardEditionWindow::save()
{
	const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
	{
		if (m_scene != nullptr)
			m_scene->save(fileName);
	}
}

void FretboardEditionWindow::switchToSelectionMode()
{
	if (m_scene != nullptr)
	{
		m_scene->switchToSelectionMode();

		m_ui->selectionAct->setDisabled(true);
		m_ui->editionAct->setEnabled(true);
	}
}

void FretboardEditionWindow::switchToEditionMode()
{
	if (m_scene != nullptr)
	{
		m_scene->switchToEditionMode();

		m_ui->editionAct->setDisabled(true);
		m_ui->selectionAct->setEnabled(true);
	}
}

void FretboardEditionWindow::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->urls().count() == 1)
	{
		const QString fileName = event->mimeData()->urls().first().toLocalFile();
		if (FretboardEditionSceneLoader::isSupported(fileName))
			event->acceptProposedAction();
	}

	QMainWindow::dragEnterEvent(event);
}

void FretboardEditionWindow::dropEvent(QDropEvent* event)
{
	Q_ASSERT_X(event->mimeData()->urls().count() == 1, "dropEvent()", "");

	const QString fileName = event->mimeData()->urls().first().toLocalFile();
	m_scene = FretboardEditionSceneLoader::tryCreateSceneFromFile(fileName);
	if (m_scene != nullptr)
		initScene();

	QMainWindow::dropEvent(event);
}

void FretboardEditionWindow::keyPressEvent(QKeyEvent* event)
{
	QMainWindow::keyPressEvent(event);

	if (event->key() == Qt::Key_Escape)
		close();
}

void FretboardEditionWindow::closeEvent(QCloseEvent* event)
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

#include "fretboardeditwindow.h"
#include "ui_fretboardeditwindow.h"
#include "fretboardeditview.h"
#include "fretboardeditscene.h"
#include "fretboardeditscenebuilder.h"

#include <QFileDialog>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

using namespace Fretboard;

FretboardEditWindow::FretboardEditWindow(QWidget* parent)
	: FretboardWindow(parent)
	, m_ui(new Ui::FretboardEditWindow)
{
	m_ui->setupUi(this);
	m_sceneBuilder.reset(new FretboardEditSceneBuilder());

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

FretboardEditView* FretboardEditWindow::view() const
{
	FretboardEditView* view = qobject_cast<FretboardEditView*>(centralWidget());
	Q_ASSERT_X(view != nullptr, "view()", "nullptr");
	return view;
}

FretboardEditScene* FretboardEditWindow::scene() const
{
	FretboardEditScene* scene = qobject_cast<FretboardEditScene*>(m_scene.data());
	Q_ASSERT_X(scene != nullptr, "scene()", "nullptr");
	return scene;
}

void FretboardEditWindow::initScene_impl()
{
	connect(m_scene.data(), SIGNAL(modified(bool)), SLOT(setWindowModified(bool)));

	m_ui->editionAct->setEnabled(true);
	m_ui->selectionAct->setEnabled(true);
}

void FretboardEditWindow::save()
{
	const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
	{
		if (m_scene != nullptr)
			scene()->save(fileName);
	}
}

void FretboardEditWindow::switchToSelectionMode()
{
	if (m_scene != nullptr)
	{
		scene()->switchToSelectionMode();

		m_ui->selectionAct->setDisabled(true);
		m_ui->editionAct->setEnabled(true);
	}
}

void FretboardEditWindow::switchToEditionMode()
{
	if (m_scene != nullptr)
	{
		scene()->switchToEditionMode();

		m_ui->editionAct->setDisabled(true);
		m_ui->selectionAct->setEnabled(true);
	}
}

void FretboardEditWindow::keyPressEvent(QKeyEvent* event)
{
	FretboardWindow::keyPressEvent(event);

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

	FretboardWindow::closeEvent(event);
}

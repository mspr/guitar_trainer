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

/*
void FretboardEditWindow::open()
{
	const QString fileName = FretboardSceneFileValidator::getOpenFileName();
	tryCreateScene(fileName);
}
*/

void FretboardEditWindow::initScene()
{
	Q_ASSERT_X(m_scene != nullptr, "initScene()", "nullptr");

	connect(m_scene.data(), SIGNAL(modified(bool)), SLOT(setWindowModified(bool)));
	editionView()->setScene(m_scene.data());
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

bool FretboardEditWindow::tryCreateScene(const QString& fileName)
{
	bool created = false;

	FretboardEditSceneBuilder sceneBuilder;
	FretboardEditScene* scene = sceneBuilder.tryCreateScene(fileName);
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

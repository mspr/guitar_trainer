#include "fretboardeditionwindow.h"
#include "ui_fretboardeditionwindow.h"
#include "fretboardeditionview.h"
#include "fretboardeditionscene.h"

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
}

FretboardEditionWindow::~FretboardEditionWindow()
{
	delete m_ui;
}

FretboardEditionView* FretboardEditionWindow::editionView() const
{
	FretboardEditionView* fretboardView = dynamic_cast<FretboardEditionView*>(centralWidget());
	Q_ASSERT_X(fretboardView != nullptr, "editionView()", "nullptr");
	return fretboardView;
}

void FretboardEditionWindow::open()
{
	const QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
		tryCreateScene(fileName);
}

bool FretboardEditionWindow::tryCreateScene(const QString& fileName)
{
	bool created = false;

	m_scene = FretboardEditionScene::tryLoad(fileName);
	if (m_scene != nullptr)
	{
		m_scene->setParent(this);
		editionView()->setScene(m_scene);
		editionView()->setMouseTracking(true);
		m_scene->setFocus();

		created = true;
	}

	return created;
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

}

void FretboardEditionWindow::switchToEditionMode()
{

}

void FretboardEditionWindow::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->urls().count() == 1)
	{
		const QString fileName = event->mimeData()->urls().first().toLocalFile();
		if (QFileInfo(fileName).suffix() == "xml")
			event->acceptProposedAction();
	}

	QMainWindow::dragEnterEvent(event);
}

void FretboardEditionWindow::dropEvent(QDropEvent* event)
{
	Q_ASSERT_X(event->mimeData()->urls().count() == 1, "dropEvent()", "");

	const QString fileName = event->mimeData()->urls().first().toLocalFile();
	if (QFileInfo(fileName).suffix() == "xml")
		tryCreateScene(fileName);

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

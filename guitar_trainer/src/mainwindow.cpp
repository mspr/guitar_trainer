#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fretboard/fretboardview.h"
#include "fretboard/fretboardeditionwindow.h"

#include <QFileDialog>

using namespace Fretboard;

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
	, m_appMode(NORMAL)
{
	m_ui->setupUi(this);

	FretboardView* fretboardView = new FretboardView(this);
	setCentralWidget(fretboardView);
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::startEdition()
{
	FretboardEditionWindow* editionWindow = new FretboardEditionWindow(this);
	editionWindow->show();
}

void MainWindow::quitApplication()
{
	qApp->quit();
}

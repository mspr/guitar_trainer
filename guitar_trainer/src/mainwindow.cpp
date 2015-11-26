#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fretboard/edition/fretboardeditwindow.h"
#include "output/outputwindow.h"

#include <QResizeEvent>

using namespace Output;
using namespace Fretboard;

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
	, m_appMode(NORMAL)
{
	m_ui->setupUi(this);

	m_outputWindow = new OutputWindow(this);
	addDockWidget(Qt::BottomDockWidgetArea, m_outputWindow);
}

MainWindow::~MainWindow()
{
	delete m_ui;
}

void MainWindow::startEdition()
{
	FretboardEditWindow* editionWindow = new FretboardEditWindow(this);
	editionWindow->show();
}

void MainWindow::quitApplication()
{
	qApp->quit();
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

	m_outputWindow->setMinimumHeight(0.15*height());
}

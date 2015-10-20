#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fretboard/fretboardeditionwindow.h"
#include "output/outputwindow.h"

#include <QResizeEvent>
#include <QDebug>

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

	qWarning() << "tryCreateScene";
	qCritical() << "tryCreateScene";
	qWarning() << "tryCreateScene";
	qCritical() << "tryCreateScene";
	qWarning() << "tryCreateScene";
	qCritical() << "tryCreateScene";
	qWarning() << "tryCreateScene";
	qCritical() << "tryCreateScene";
	qWarning() << "tryCreateScene";
	qCritical() << "tryCreateScene";
	qWarning() << "tryCreateScene";
	qCritical() << "tryCreateScene";
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

void MainWindow::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

	m_outputWindow->setMinimumHeight(0.15*height());
}

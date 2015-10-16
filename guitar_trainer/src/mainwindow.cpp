#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fretboard/fretboardeditionwindow.h"
#include "outputwindow.h"

#include <QDebug>

using namespace Fretboard;

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
	, m_appMode(NORMAL)
{
	m_ui->setupUi(this);

	OutputWindow* outputWindow = new OutputWindow(this);
	addDockWidget(Qt::BottomDockWidgetArea, outputWindow);

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

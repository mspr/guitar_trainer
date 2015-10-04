#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fretboardview.h"

#include <QFileDialog>

using namespace View;

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
	if (m_appMode == NORMAL)
	{
		const QString fileName = QFileDialog::getOpenFileName(this, tr("Open xml file"), "", tr("Xml Files (*.xml)"));

		m_appMode = EDITION;
	}
}

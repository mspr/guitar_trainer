#include "fretboardplaywindow.h"
#include "ui_fretboardplaywindow.h"
#include "parameter/chordparameterwidget.h"
#include "fretboard/edition/fretboardeditwindow.h"
#include "fretboard/fretboardview.h"
#include "fretboardplayscenebuilder.h"
#include "output/outputwindow.h"

using namespace Fretboard;
using namespace Parameter;
using namespace Output;

FretboardPlayWindow::FretboardPlayWindow(QWidget* parent)
	: FretboardWindow(parent)
	, m_ui(new Ui::FretboardPlayWindow)
{
	m_ui->setupUi(this);

	m_sceneBuilder.reset(new FretboardPlaySceneBuilder());

	FretboardView* fretboardView = new FretboardView(this);
	setCentralWidget(fretboardView);

	ChordParameterWidget* chordParameterWidget = new ChordParameterWidget();
	addDockWidget(Qt::LeftDockWidgetArea, chordParameterWidget); // TODO check ownership of the dock widget

	m_outputWindow = new OutputWindow(this);
	addDockWidget(Qt::BottomDockWidgetArea, m_outputWindow);
}

FretboardPlayWindow::~FretboardPlayWindow()
{
	delete m_ui;
}

void FretboardPlayWindow::initScene_impl()
{

}

void FretboardPlayWindow::startEdition()
{
	FretboardEditWindow* editionWindow = new FretboardEditWindow(this);
	editionWindow->show();
}

void FretboardPlayWindow::quitApplication()
{
	qApp->quit();
}

void FretboardPlayWindow::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);

	m_outputWindow->setMinimumHeight(0.15*height());
}

#include "fretboardplaywindow.h"
#include "ui_fretboardplaywindow.h"
#include "parameter/chordparameterwidget.h"

using namespace Fretboard;
using namespace Parameter;

FretboardPlayWindow::FretboardPlayWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::FretboardPlayWindow)
{
	m_ui->setupUi(this);

	ChordParameterWidget* chordParameterWidget = new ChordParameterWidget();
	addDockWidget(Qt::LeftDockWidgetArea, chordParameterWidget); // TODO check ownership of the dock widget
}

FretboardPlayWindow::~FretboardPlayWindow()
{
	delete m_ui;
}

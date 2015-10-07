#include "fretboardeditionwindow.h"
#include "ui_fretboardeditionwindow.h"
#include "fretboard/fretboardview.h"

using namespace Fretboard;

FretboardEditionWindow::FretboardEditionWindow(const QString& fileName, QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::FretboardEditionWindow)
{
	m_ui->setupUi(this);

	FretboardView* fretboardView = new FretboardView(this);
	fretboardView->initScene(fileName);
	setCentralWidget(fretboardView);
}

FretboardEditionWindow::~FretboardEditionWindow()
{
	delete m_ui;
}

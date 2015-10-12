#include "fretboardeditionwindow.h"
#include "ui_fretboardeditionwindow.h"
#include "fretboard/fretboardeditionview.h"

#include <QFileDialog>

using namespace Fretboard;

FretboardEditionWindow::FretboardEditionWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::FretboardEditionWindow)
{
	m_ui->setupUi(this);

	FretboardEditionView* fretboardView = new FretboardEditionView(this);
	setCentralWidget(fretboardView);
}

FretboardEditionWindow::~FretboardEditionWindow()
{
	delete m_ui;
}

void FretboardEditionWindow::open()
{
	const QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
	{
		FretboardEditionView* fretboardView = dynamic_cast<FretboardEditionView*>(centralWidget());
		Q_ASSERT_X(fretboardView != nullptr, "open()", "nullptr");
		fretboardView->initScene(fileName);
	}
}

void FretboardEditionWindow::save()
{
	const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
	{
		FretboardEditionView* fretboardView = dynamic_cast<FretboardEditionView*>(centralWidget());
		Q_ASSERT_X(fretboardView != nullptr, "save()", "nullptr");
		fretboardView->saveScene(fileName);
	}
}

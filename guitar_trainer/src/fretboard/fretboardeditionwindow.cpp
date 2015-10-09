#include "fretboardeditionwindow.h"
#include "ui_fretboardeditionwindow.h"
#include "fretboard/fretboardview.h"

#include <QFileDialog>

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

void FretboardEditionWindow::save()
{

	const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Xml Files (*.xml)"));
	if (!fileName.isNull())
	{
		FretboardView* fretboardView = dynamic_cast<FretboardView*>(centralWidget());
		Q_ASSERT_X(fretboardView != nullptr, "save()", "nullptr");
		fretboardView->saveScene(fileName);
	}
}

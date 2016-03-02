#include "chordparameterwidget.h"
#include "ui_chordparameterwidget.h"
#include "chordeditor.h"

using namespace Parameter;

ChordParameterWidget::ChordParameterWidget(QWidget* parent)
	: QDockWidget(parent)
	, m_ui(new Ui::ChordParameterWidget)
{
	m_ui->setupUi(this);
}

ChordParameterWidget::~ChordParameterWidget()
{
	delete m_ui;
}

void ChordParameterWidget::openChordEditor()
{
	m_chordEditor.reset(new ChordEditor());
	m_chordEditor->show();
}

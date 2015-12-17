#include "chordparameterwidget.h"
#include "ui_chordparameterwidget.h"
#include "chordeditor.h"
#include "music/interval.h"

using namespace Parameter;
using namespace Music;

ChordParameterWidget::ChordParameterWidget(QWidget* parent)
	: QDockWidget(parent)
	, m_ui(new Ui::ChordParameterWidget)
{
	m_ui->setupUi(this);

	QHBoxLayout* intervalLyt = new QHBoxLayout(this);
	setLayout(intervalLyt);

	const QHash<Interval::Type, QString> intervalShortNames = Interval::intervalShortNames();
	foreach (const QString name, intervalShortNames)
	{
		QLabel* intervalLbl = new QLabel(name);
		intervalLyt->addWidget(intervalLbl);
	}
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

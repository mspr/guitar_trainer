#include "chordeditor.h"
#include "intervalslider.h"
#include "intervallistwidget.h"

#include <QHBoxLayout>

using namespace Parameter;

ChordEditor::ChordEditor(QWidget* parent)
	: QWidget(parent)
{
	setupUi();
}

void ChordEditor::setupUi()
{
	QHBoxLayout* mainLyt = new QHBoxLayout();
	setLayout(mainLyt);

	IntervalListWidget* intervalListWidget = new IntervalListWidget();
	mainLyt->addWidget(intervalListWidget);
	IntervalSlider* intervalSlider = new IntervalSlider();
	mainLyt->addWidget(intervalSlider);
}

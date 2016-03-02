#include "intervalslider.h"

#include <QVBoxLayout>
#include <QSlider>
#include <QLabel>

using namespace Parameter;

IntervalSlider::IntervalSlider(QWidget* parent)
	: QWidget(parent)
{
	setupUi();
}

void IntervalSlider::setupUi()
{
	QVBoxLayout* intervalLyt = new QVBoxLayout();
	setLayout(intervalLyt);

	QHBoxLayout* intervalNamesLyt = new QHBoxLayout();
	intervalLyt->addLayout(intervalNamesLyt);

	QSlider* slider = new QSlider(Qt::Horizontal);
	slider->setTickPosition(QSlider::TicksBelow);
	intervalLyt->addWidget(slider);

	QHBoxLayout* demiToneScaleLyt = new QHBoxLayout();
	intervalLyt->addLayout(demiToneScaleLyt);
	for (int i=0; i<15; ++i)
	{
		QLabel* demiToneMarkerLbl = new QLabel(QString::number(i));
		demiToneScaleLyt->addWidget(demiToneMarkerLbl);
	}
}

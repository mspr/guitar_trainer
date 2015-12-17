#include "intervalslider.h"

#include <QVBoxLayout>
#include <QSlider>

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
	intervalLyt->addWidget(slider);
}

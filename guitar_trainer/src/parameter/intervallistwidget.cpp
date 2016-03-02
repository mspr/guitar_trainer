#include "intervallistwidget.h"
#include "music/interval.h"

#include <QVBoxLayout>
#include <QLabel>

using namespace Parameter;
using namespace Music;

IntervalListWidget::IntervalListWidget(QWidget* parent)
	: QWidget(parent)
{
	QVBoxLayout* mainLyt = new QVBoxLayout();
	setLayout(mainLyt);

	const QMap<Interval::Type, QStringList> intervalQualifications = Interval::intervalQualifications();
	foreach (const QStringList intervalQualificationsName, intervalQualifications)
	{
		QHBoxLayout* intervalLyt = new QHBoxLayout();
		mainLyt->addLayout(intervalLyt);

		foreach (const QString intervalQualificationName, intervalQualificationsName)
		{
			QLabel* intervalQualificationLbl = new QLabel(intervalQualificationName);
			intervalLyt->addWidget(intervalQualificationLbl);
		}
	}
}

#ifndef INTERVALLISTWIDGET_H
#define INTERVALLISTWIDGET_H

#include <QListWidget>

namespace Parameter
{
	class IntervalListWidget : public QListWidget
	{
		public:
			IntervalListWidget(QWidget* parent = 0);
	};

} // Parameter

#endif // INTERVALLISTWIDGET_H

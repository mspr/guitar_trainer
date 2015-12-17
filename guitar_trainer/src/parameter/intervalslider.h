#ifndef INTERVALSLIDER_H
#define INTERVALSLIDER_H

#include <QWidget>

namespace Parameter
{
	class IntervalSlider : public QWidget
	{
		public:
			IntervalSlider(QWidget* parent = 0);

		private:
			void setupUi();
	};

} // Parameter

#endif // INTERVALSLIDER_H

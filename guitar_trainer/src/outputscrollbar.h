#ifndef OUTPUTSCROLLBAR_H
#define OUTPUTSCROLLBAR_H

#include <QScrollBar>

class OutputScrollBar : public QScrollBar
{
	public:
		OutputScrollBar(QWidget* parent = nullptr);

	protected:
		virtual void sliderChange(SliderChange sliderChange) override;
};

#endif // OUTPUTSCROLLBAR_H

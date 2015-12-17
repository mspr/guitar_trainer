#ifndef FRETBOARDPLAYWINDOW_H
#define FRETBOARDPLAYWINDOW_H

#include <QMainWindow>

namespace Ui { class FretboardPlayWindow; }

namespace Fretboard
{
	class FretboardPlayWindow : public QMainWindow
	{
			Q_OBJECT

		public:
			explicit FretboardPlayWindow(QWidget* parent = 0);
			~FretboardPlayWindow();

		private:
			Ui::FretboardPlayWindow* m_ui;
	};

} // Fretboard

#endif // FRETBOARDPLAYWINDOW_H

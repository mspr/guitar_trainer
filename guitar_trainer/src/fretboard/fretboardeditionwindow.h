#ifndef FRETBOARDEDITIONWINDOW_H
#define FRETBOARDEDITIONWINDOW_H

#include <QMainWindow>

namespace Ui { class FretboardEditionWindow; }

namespace Fretboard
{
	class FretboardEditionWindow : public QMainWindow
	{
		Q_OBJECT

		public:
			explicit FretboardEditionWindow(QWidget* parent = 0);
			~FretboardEditionWindow();

		private slots:
			void open();
			void save();

		private:
			Ui::FretboardEditionWindow* m_ui;
	};

} // Fretboard

#endif // FRETBOARDEDITIONWINDOW_H

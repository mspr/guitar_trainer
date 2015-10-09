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
			explicit FretboardEditionWindow(const QString& fileName, QWidget* parent = 0);
			~FretboardEditionWindow();

		private slots:
			void save();

		private:
			Ui::FretboardEditionWindow* m_ui;
	};

} // Fretboard

#endif // FRETBOARDEDITIONWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

namespace View
{
	class MainWindow : public QMainWindow
	{
		Q_OBJECT

		enum AppMode
		{
			EDITION,
			NORMAL
		};

		public:
			explicit MainWindow(QWidget* parent = 0);
			~MainWindow();

		private slots:
			void startEdition();

		private:
			Ui::MainWindow* m_ui;
			AppMode m_appMode;
	};

} // View

#endif // MAINWINDOW_H
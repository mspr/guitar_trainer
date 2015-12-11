#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }
namespace Output { class OutputWindow; }

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

	protected:
		virtual void resizeEvent(QResizeEvent* event) override;

	private slots:
		void open();
		void startEdition();
		void quitApplication();

	private:
		Ui::MainWindow* m_ui;
		AppMode m_appMode;
		Output::OutputWindow* m_outputWindow;
};

#endif // MAINWINDOW_H

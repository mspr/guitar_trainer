#ifndef OUTPUTWINDOW_H
#define OUTPUTWINDOW_H

#include <QDockWidget>

namespace Ui { class OutputWindow; }

class OutputWindow : public QDockWidget
{
	Q_OBJECT

	public:
		explicit OutputWindow(QWidget* parent = 0);
		~OutputWindow();

	private:
		static void showMessage(QtMsgType type, const QString& msg);

	private:
		Ui::OutputWindow* m_ui;
};

#endif // OUTPUTWINDOW_H

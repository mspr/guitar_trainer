#include "outputwindow.h"
#include "ui_outputwindow.h"
#include "messagehandler.h"

OutputWindow::OutputWindow(QWidget* parent)
	: QDockWidget(parent)
	, m_ui(new Ui::OutputWindow)
{
	m_ui->setupUi(this);

	setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

	MessageHandler::registerOutputWindow(this);
}

OutputWindow::~OutputWindow()
{
	delete m_ui;
}

void OutputWindow::showMessage(QtMsgType type, const QString& msg)
{
}

#include "outputwindow.h"
#include "ui_outputwindow.h"
#include "messagehandler.h"

#include <QLabel>

OutputWindow::OutputWindow(QWidget* parent)
	: QDockWidget(parent)
	, m_ui(new Ui::OutputWindow)
{
	m_ui->setupUi(this);

	setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
	setTitleBarWidget(new QWidget());

	MessageHandler::registerOutputWindow(this);
}

OutputWindow::~OutputWindow()
{
	delete m_ui;
}

void OutputWindow::showMessage(QtMsgType type, const QString& msg)
{
	QGridLayout* layout = dynamic_cast<QGridLayout*>(m_ui->scrollAreaWidgetContents->layout());
	Q_ASSERT_X(layout != nullptr, "showMessage()", "nullptr");
	const int rowIdx = layout->rowCount();

	QLabel* iconLabel = new QLabel();
	switch (type)
	{
		case QtDebugMsg:
		break;
#if QT_VERSION >= 0x050500
		case QtInfoMsg:
			iconLabel->setPixmap(QPixmap(":/images/info.png"));
		break;
#endif
		case QtWarningMsg:
			iconLabel->setPixmap(QPixmap(":/images/warning.png"));
		break;
		case QtCriticalMsg:
			iconLabel->setPixmap(QPixmap(":/images/error.png"));
		break;
		case QtFatalMsg:
		break;
	}

	iconLabel->setMaximumSize(iconLabel->pixmap()->size());
	layout->addWidget(iconLabel, rowIdx, 0, 1, 1);

	QLabel* msgLabel = new QLabel(msg);
	layout->addWidget(msgLabel, rowIdx, 1, 1, 1);
}

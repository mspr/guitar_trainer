#include "messagehandler.h"

OutputWindow* MessageHandler::s_outputWindow = nullptr;

MessageHandler::MessageHandler()
{
}

/*static*/ void MessageHandler::registerOutputWindow(OutputWindow* outputWindow)
{
	Q_ASSERT_X(outputWindow != nullptr, "registerOutputWindow()", "nullptr");
	s_outputWindow = outputWindow;
}

/*static*/ void MessageHandler::handleMessage(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
	switch (type)
	{
		case QtDebugMsg:
		break;
#if QT_VERSION >= 0x050500
		case QtInfoMsg:
		break;
#endif
		case QtWarningMsg:
		break;
		case QtCriticalMsg:
		break;
		case QtFatalMsg:
		break;
	}
}

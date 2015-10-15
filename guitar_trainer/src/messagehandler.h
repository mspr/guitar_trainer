#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QtMsgHandler>

class OutputWindow;

class MessageHandler
{
	public:
		MessageHandler();

		static void registerOutputWindow(OutputWindow* outputWindow);
		static void handleMessage(QtMsgType type, const QMessageLogContext& context, const QString& msg);

	private:
		static OutputWindow* s_outputWindow;
};

#endif // MESSAGEHANDLER_H

#include <QApplication>
#include "mainwindow.h"
#include "messagehandler.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	qInstallMessageHandler(MessageHandler::handleMessage);

	MainWindow w;
	w.showFullScreen();

	return a.exec();
}

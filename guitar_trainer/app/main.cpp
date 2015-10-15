#include <QApplication>
#include "mainwindow.h"
#include "messagehandler.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	MainWindow w;
	w.showFullScreen();

	qInstallMessageHandler(MessageHandler::handleMessage);

	return a.exec();
}

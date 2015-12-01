#include "application.h"
#include "mainwindow.h"
#include "messagehandler.h"

#include <QDebug>

int main(int argc, char* argv[])
{
	Application a(argc, argv);

	const QString styleSheetFileName = ":/app.qss";
	if (!a.loadStyleSheet(styleSheetFileName))
		qWarning() << QString("Impossible to load style sheet file %1.").arg(styleSheetFileName);

	qInstallMessageHandler(MessageHandler::handleMessage);

	MainWindow w;
	w.showFullScreen();

	return a.exec();
}

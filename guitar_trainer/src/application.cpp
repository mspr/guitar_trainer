#include "application.h"

#include <QFile>
#include <QTextStream>

Application::Application(int& argc, char** argv)
	: QApplication(argc, argv) {}

bool Application::loadStyleSheet(const QString& fileName)
{
	bool ret = false;

	QFile file(fileName);
	if (file.open(QFile::ReadOnly))
	{
		QTextStream styleIn(&file);
		setStyleSheet(styleIn.readAll());
		file.close();
		ret = true;
	}

	return ret;
}

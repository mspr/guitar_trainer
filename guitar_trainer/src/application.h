#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class Application : public QApplication
{
	public :
		Application(int& argc, char** argv);

		bool loadStyleSheet(const QString& fileName);
};

#endif // APPLICATION_H

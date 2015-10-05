#ifndef TESTNOTE_H
#define TESTNOTE_H

#include <QObject>

class TestNote : public QObject
{
	Q_OBJECT

	public slots:
		void toString();
		void toNote();
		void notes();
};

#endif // TESTNOTE_H

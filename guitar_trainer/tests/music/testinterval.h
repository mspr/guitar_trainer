#ifndef TESTINTERVAL_H
#define TESTINTERVAL_H

#include <QObject>

class TestInterval : public QObject
{
	Q_OBJECT

	public slots:
		void toString();
		void toInterval();
		void toSemiTone();
		void intervals();
};

#endif // TESTINTERVAL_H

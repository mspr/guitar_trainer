#include "music/testnote.h"
#include "music/testinterval.h"

#include <QTest>

int main(int argc, char* argv[])
{
	TestNote testNote;
	QTest::qExec(&testNote, argc, argv);

	TestInterval testInterval;
	QTest::qExec(&testInterval, argc, argv);

	return 0;
}

#include "interval.h"
#include "intervalqualification.h"

#include <QStringList>

using namespace Music;

/*static*/ QHash<Interval::Type, QString> Interval::initIntervalShortNames()
{
	QHash<Type, QString> intervalNames;

	intervalNames.insert(Type::UNISON, "T");
	intervalNames.insert(Type::SECOND, "2");
	intervalNames.insert(Type::THIRD, "3");
	intervalNames.insert(Type::FOURTH, "4");
	intervalNames.insert(Type::FIFTH, "5");
	intervalNames.insert(Type::SIXTH, "6");
	intervalNames.insert(Type::SEVENTH, "7");
	intervalNames.insert(Type::OCTAVE, "8v");

	return intervalNames;
}

/*static*/ QHash<Interval::Type, QString> Interval::initIntervalFullNames()
{
	QHash<Type, QString> intervalNames;

	intervalNames.insert(Type::UNISON, "Unison");
	intervalNames.insert(Type::SECOND, "Second");
	intervalNames.insert(Type::THIRD, "Third");
	intervalNames.insert(Type::FOURTH, "Fourth");
	intervalNames.insert(Type::FIFTH, "Fifth");
	intervalNames.insert(Type::SIXTH, "Sixth");
	intervalNames.insert(Type::SEVENTH, "Seventh");
	intervalNames.insert(Type::OCTAVE, "Octave");

	return intervalNames;
}

/*static*/ QMap<Interval::Type, QStringList> Interval::initIntervalQualifications()
{
	QMap<Type, QStringList> intervalQualifications;

	const QString unisonShortName = s_intervalShortNames.value(Type::UNISON);
	intervalQualifications.insert(Type::UNISON, QStringList() << unisonShortName);

	const QString secondShortName = s_intervalShortNames.value(Type::SECOND);
	intervalQualifications.insert(Type::SECOND,
																QStringList() << secondShortName + IntervalQualification::shortName(IntervalQualification::Type::DIMINISHED)
																							<< secondShortName + IntervalQualification::shortName(IntervalQualification::Type::MINOR)
																							<< secondShortName + IntervalQualification::shortName(IntervalQualification::Type::MAJOR)
																							<< secondShortName + IntervalQualification::shortName(IntervalQualification::Type::AUGMENTED));

	const QString thirdShortName = s_intervalShortNames.value(Type::THIRD);
	intervalQualifications.insert(Type::THIRD,
																QStringList()	<< thirdShortName + IntervalQualification::shortName(IntervalQualification::Type::DIMINISHED)
																							<< thirdShortName + IntervalQualification::shortName(IntervalQualification::Type::MINOR)
																							<< thirdShortName + IntervalQualification::shortName(IntervalQualification::Type::MAJOR)
																							<< thirdShortName + IntervalQualification::shortName(IntervalQualification::Type::AUGMENTED));

	const QString fourthShortName = s_intervalShortNames.value(Type::FOURTH);
	intervalQualifications.insert(Type::FOURTH,
																QStringList() << fourthShortName + IntervalQualification::shortName(IntervalQualification::Type::DIMINISHED)
																							<< fourthShortName + IntervalQualification::shortName(IntervalQualification::Type::PERFECT)
																							<< fourthShortName + IntervalQualification::shortName(IntervalQualification::Type::AUGMENTED));

	const QString fifthShortName = s_intervalShortNames.value(Type::FIFTH);
	intervalQualifications.insert(Type::FIFTH,
																QStringList()	<< fifthShortName + IntervalQualification::shortName(IntervalQualification::Type::DIMINISHED)
																							<< fifthShortName + IntervalQualification::shortName(IntervalQualification::Type::PERFECT)
																							<< fifthShortName + IntervalQualification::shortName(IntervalQualification::Type::AUGMENTED));

	const QString sixthShortName = s_intervalShortNames.value(Type::SIXTH);
	intervalQualifications.insert(Type::SIXTH,
																QStringList()	<< sixthShortName + IntervalQualification::shortName(IntervalQualification::Type::DIMINISHED)
																							<< sixthShortName + IntervalQualification::shortName(IntervalQualification::Type::MINOR)
																							<< sixthShortName + IntervalQualification::shortName(IntervalQualification::Type::MAJOR)
																							<< sixthShortName + IntervalQualification::shortName(IntervalQualification::Type::AUGMENTED));

	const QString seventhShortName = s_intervalShortNames.value(Type::SEVENTH);
	intervalQualifications.insert(Type::SEVENTH,
																QStringList()	<< seventhShortName + IntervalQualification::shortName(IntervalQualification::Type::DIMINISHED)
																							<< seventhShortName + IntervalQualification::shortName(IntervalQualification::Type::MINOR)
																							<< seventhShortName + IntervalQualification::shortName(IntervalQualification::Type::MAJOR)
																							<< seventhShortName + IntervalQualification::shortName(IntervalQualification::Type::AUGMENTED));

	const QString OctaveShortName = s_intervalShortNames.value(Type::OCTAVE);
	intervalQualifications.insert(Type::OCTAVE, QStringList() << OctaveShortName);

	return intervalQualifications;
}

QHash<Interval::Type, QString> Interval::s_intervalShortNames = Interval::initIntervalShortNames();
QHash<Interval::Type, QString> Interval::s_intervalFullNames = Interval::initIntervalFullNames();
QMap<Interval::Type, QStringList> Interval::s_intervalQualifications = Interval::initIntervalQualifications();

/*static*/ const QHash<Interval::Type, QString>& Interval::intervalShortNames()
{
	return s_intervalShortNames;
}

/*static*/ const QMap<Interval::Type, QStringList>& Interval::intervalQualifications()
{
	return s_intervalQualifications;
}

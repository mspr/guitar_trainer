#include "interval.h"

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

/*static*/ QHash<Interval::Type, QList<IntervalQualification::Type> > Interval::initIntervalQualifications()
{
	QHash<Type, QList<IntervalQualification::Type>> intervalQualifications;

	QList<IntervalQualification::Type> qualPerf;
	qualPerf.append(IntervalQualification::Type::PERFECT);

	QList<IntervalQualification::Type> qualMinMajDimAug;
	qualMinMajDimAug.append(IntervalQualification::Type::DIMINISHED);
	qualMinMajDimAug.append(IntervalQualification::Type::MINOR);
	qualMinMajDimAug.append(IntervalQualification::Type::MAJOR);
	qualMinMajDimAug.append(IntervalQualification::Type::AUGMENTED);

	QList<IntervalQualification::Type> qualPerfDimAug;
	qualPerfDimAug.append(IntervalQualification::Type::DIMINISHED);
	qualPerfDimAug.append(IntervalQualification::Type::PERFECT);
	qualPerfDimAug.append(IntervalQualification::Type::AUGMENTED);

	intervalQualifications.insert(Type::UNISON, qualPerf);
	intervalQualifications.insert(Type::SECOND, qualMinMajDimAug);
	intervalQualifications.insert(Type::THIRD, qualMinMajDimAug);
	intervalQualifications.insert(Type::FOURTH, qualPerfDimAug);
	intervalQualifications.insert(Type::FIFTH, qualPerfDimAug);
	intervalQualifications.insert(Type::SIXTH, qualMinMajDimAug);
	intervalQualifications.insert(Type::SEVENTH, qualMinMajDimAug);
	intervalQualifications.insert(Type::OCTAVE, qualPerf);

	return intervalQualifications;
}

QHash<Interval::Type, QString> Interval::s_intervalShortNames = Interval::initIntervalShortNames();
QHash<Interval::Type, QString> Interval::s_intervalFullNames = Interval::initIntervalFullNames();
QHash<Interval::Type, QList<IntervalQualification::Type>> Interval::s_intervalQualifications = Interval::initIntervalQualifications();

/*static*/ const QHash<Interval::Type, QString>& Interval::intervalShortNames()
{
	return s_intervalShortNames;
}

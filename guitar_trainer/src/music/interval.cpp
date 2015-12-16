#include "interval.h"

using namespace Music;

QHash<Interval::Type, QString> Interval::initIntervalNames()
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

QHash<Interval::Type, QList<IntervalQualification::Type> > Interval::initIntervalQualifications()
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

QHash<Interval::Type, QString> Interval::s_intervalNames = Interval::initIntervalNames();
QHash<Interval::Type, QList<IntervalQualification::Type>> Interval::s_intervalQualifications = Interval::initIntervalQualifications();

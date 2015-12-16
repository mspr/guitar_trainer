#include "intervalqualification.h"

using namespace Music;

/*static*/ QHash<IntervalQualification::Type, QString> IntervalQualification::initIntervalQualifications()
{
	QHash<Type, QString> qualifications;

	qualifications.insert(Type::DIMINISHED, "Diminished");
	qualifications.insert(Type::MINOR, "Minor");
	qualifications.insert(Type::PERFECT, "Perfect");
	qualifications.insert(Type::MAJOR, "Major");
	qualifications.insert(Type::AUGMENTED, "Augmented");

	return qualifications;
}

QHash<IntervalQualification::Type, QString> IntervalQualification::s_intervalQualifications = IntervalQualification::initIntervalQualifications();

/*static*/ QHash<IntervalQualification::Type, QString>& IntervalQualification::intervalQualifications()
{
	return s_intervalQualifications;
}

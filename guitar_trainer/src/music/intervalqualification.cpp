#include "intervalqualification.h"

using namespace Music;

/*static*/ QHash<IntervalQualification::Type, QString> IntervalQualification::initQualificationShortNames()
{
	QHash<Type, QString> qualifications;

	qualifications.insert(Type::DIMINISHED, "dim");
	qualifications.insert(Type::MINOR, "m");
	qualifications.insert(Type::PERFECT, "j");
	qualifications.insert(Type::MAJOR, "M");
	qualifications.insert(Type::AUGMENTED, "aug");

	return qualifications;
}

/*static*/ QHash<IntervalQualification::Type, QString> IntervalQualification::initQualificationFullNames()
{
	QHash<Type, QString> qualifications;

	qualifications.insert(Type::DIMINISHED, "Diminished");
	qualifications.insert(Type::MINOR, "Minor");
	qualifications.insert(Type::PERFECT, "Perfect");
	qualifications.insert(Type::MAJOR, "Major");
	qualifications.insert(Type::AUGMENTED, "Augmented");

	return qualifications;
}

QHash<IntervalQualification::Type, QString> IntervalQualification::s_qualificationShortNames = IntervalQualification::initQualificationShortNames();
QHash<IntervalQualification::Type, QString> IntervalQualification::s_qualificationFullNames = IntervalQualification::initQualificationFullNames();

/*static*/ QHash<IntervalQualification::Type, QString>& IntervalQualification::qualificationShortNames()
{
	return s_qualificationShortNames;
}

/*static*/ QHash<IntervalQualification::Type, QString>& IntervalQualification::qualificationFullNames()
{
	return s_qualificationFullNames;
}

#include "intervalqualification.h"

#include <QList>

using namespace Music;

/*static*/ QList<IntervalQualification> IntervalQualification::initIntervalQualifications()
{
	QList<IntervalQualification> qualifications;

	qualifications.append(IntervalQualification(Type::DIMINISHED, "Diminished"));
	qualifications.append(IntervalQualification(Type::MINOR, "Minor"));
	qualifications.append(IntervalQualification(Type::PERFECT, "Perfect"));
	qualifications.append(IntervalQualification(Type::MAJOR, "Major"));
	qualifications.append(IntervalQualification(Type::AUGMENTED, "Augmented"));

	return qualifications;
}

QList<IntervalQualification> IntervalQualification::s_intervalQualifications = IntervalQualification::initIntervalQualifications();

/*static*/ QList<IntervalQualification>& IntervalQualification::intervalQualifications()
{
	return s_intervalQualifications;
}

IntervalQualification::IntervalQualification(const Type type, const QString& name)
	: m_type(type)
	, m_name(name)
{
}

IntervalQualification::Type IntervalQualification::type() const
{
	return m_type;
}

QString IntervalQualification::name() const
{
	return m_name;
}

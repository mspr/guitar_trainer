#include "interval.h"

#include <QStringList>

using namespace Model;

const QHash<Interval::EInterval, QString> Interval::s_strByInterval = Interval::initStrByInterval();

/*static*/ QHash<Interval::EInterval, QString> Interval::initStrByInterval()
{
	QHash<EInterval, QString> strByInterval;

	strByInterval.insert(PERFECT_UNISON, "Perfect Unison");
	strByInterval.insert(MINOR_SECOND, "Minor Second");
	strByInterval.insert(MAJOR_SECOND, "Mahor Second");
	strByInterval.insert(MINOR_THIRD, "Minor Third");
	strByInterval.insert(MAJOR_THIRD, "Major Third");
	strByInterval.insert(PERFECT_FOURTH, "Perfect Fourth");
	strByInterval.insert(DIMINISHED_FIFTH, "Diminished Fifth");
	strByInterval.insert(PERFECT_FIFTH, "Perfect Fifth");
	strByInterval.insert(MINOR_SIXTH, "Minor Sixth");
	strByInterval.insert(MAJOR_SIXTH, "Major Sixth");
	strByInterval.insert(MINOR_SEVENTH, "Minor Seventh");
	strByInterval.insert(MAJOR_SEVENTH, "Major Seventh");
	strByInterval.insert(PERFECT_OCTAVE, "Perfect Octave");
	strByInterval.insert(MINOR_NINTH, "Minor Ninth");
	strByInterval.insert(MAJOR_NINTH, "Major Ninth");
	strByInterval.insert(MINOR_TENTH, "Minor Tenth");
	strByInterval.insert(MAJOR_TENTH, "Major Tenth");
	strByInterval.insert(PERFECT_ELEVENTH, "Perfect Eleventh");
	strByInterval.insert(DIMINISHED_TWELFTH, "Diminished Twelfth");
	strByInterval.insert(PERFECT_TWELFTH, "Perfect Twelfth");
	strByInterval.insert(MINOR_THIRTEENTH, "Minor Thirteenth");
	strByInterval.insert(MAJOR_THIRTEENTH, "Major Thirteenth");
	strByInterval.insert(MINOR_FOURTEENTH, "Minor Fourteenth");
	strByInterval.insert(MAJOR_FOURTEENTH, "Major Fourteenth");
	strByInterval.insert(PERFECT_FIFTEENTH, "Perfect Fifteenth");
	strByInterval.insert(AUGMENTED_FIFTEENTH, "Augmented Fifteenth");

	return strByInterval;
}

/*static*/ QString Interval::toString(EInterval interval)
{
	return s_strByInterval.value(interval);
}

/*static*/ Interval::EInterval Interval::toInterval(const QString& intervalStr)
{
	return s_strByInterval.key(intervalStr);
}

/*static*/ Interval::EInterval Interval::toInterval(const uint semiTone)
{
	Q_ASSERT_X(semiTone < 26, "toInterval", "Semitone is too high to be supported.");

	return (EInterval)semiTone;
}

/*static*/ uint Interval::toSemiTone(EInterval interval)
{
	return (uint)interval;
}

/*static*/ QStringList Interval::intervals()
{
	return s_strByInterval.values();
}

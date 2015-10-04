#include "interval.h"

#include <QStringList>

using namespace Model;

const QHash<Interval::EMinMajPerfect, QString> Interval::s_strByMinMajPerfect = Interval::initStrByMinMajPerfect();
const QHash<Interval::EDimAug, QString> Interval::s_strByDimAug = Interval::initStrByDimAug();

/*static*/ QHash<Interval::EMinMajPerfect, QString> Interval::initStrByMinMajPerfect()
{
	QHash<EMinMajPerfect, QString> strByMinMajPerfect;

	strByMinMajPerfect.insert(PERFECT_UNISON, "Perfect Unison");
	strByMinMajPerfect.insert(MINOR_SECOND, "Minor Second");
	strByMinMajPerfect.insert(MAJOR_SECOND, "Mahor Second");
	strByMinMajPerfect.insert(MINOR_THIRD, "Minor Third");
	strByMinMajPerfect.insert(MAJOR_THIRD, "Major Third");
	strByMinMajPerfect.insert(PERFECT_FOURTH, "Perfect Fourth");
	strByMinMajPerfect.insert(PERFECT_FIFTH, "Perfect Fifth");
	strByMinMajPerfect.insert(MINOR_SIXTH, "Minor Sixth");
	strByMinMajPerfect.insert(MAJOR_SIXTH, "Major Sixth");
	strByMinMajPerfect.insert(MINOR_SEVENTH, "Minor Seventh");
	strByMinMajPerfect.insert(MAJOR_SEVENTH, "Major Seventh");
	strByMinMajPerfect.insert(PERFECT_OCTAVE, "Perfect Octave");

	return strByMinMajPerfect;
}

/*static*/ QHash<Interval::EDimAug, QString> Interval::initStrByDimAug()
{
	QHash<EDimAug, QString> strByDimAug;

	strByDimAug.insert(DIMINISHED_SECOND, "Diminished Second");
	strByDimAug.insert(AUGMENTED_UNISON, "Augmented Unison");
	strByDimAug.insert(DIMINISHED_THIRD, "Diminished Third");
	strByDimAug.insert(AUGMENTED_SECOND, "Augmented Second");
	strByDimAug.insert(DIMINISHED_FOURTH, "Diminished Fourth");
	strByDimAug.insert(AUGMENTED_THIRD, "Augmented Third");
	strByDimAug.insert(DIMINISHED_FIFTH, "Diminished Fifth");
	strByDimAug.insert(AUGMENTED_FOURTH, "Augmented Fourth");
	strByDimAug.insert(DIMINISHED_SIXTH, "Diminished Sixth");
	strByDimAug.insert(AUGMENTED_FIFTH, "Augmented Fifth");
	strByDimAug.insert(DIMINISHED_SEVENTH, "Diminished Seventh");
	strByDimAug.insert(AUGMENTED_SIXTH, "Augmented Sixth");
	strByDimAug.insert(DIMINISHED_OCTAVE, "Diminished Octave");
	strByDimAug.insert(AUGMENTED_SEVENTH, "Augmented Seventh");

	return strByDimAug;
}

/*static*/ QString Interval::toString(EMinMajPerfect interval)
{
	return s_strByMinMajPerfect.value(interval);
}

/*static*/ Interval::EMinMajPerfect Interval::toMinMajPerfect(const QString& intervalStr)
{
	return s_strByMinMajPerfect.key(intervalStr);
}

/*static*/ QStringList Interval::minMajPerfectIntervals()
{
	return s_strByMinMajPerfect.values();
}

/*static*/ QString Interval::toString(EDimAug interval)
{
	return s_strByDimAug.value(interval);
}

/*static*/ Interval::EDimAug Interval::toDimAug(const QString& intervalStr)
{
	return s_strByDimAug.key(intervalStr);
}

/*static*/ QStringList Interval::dimAugIntervals()
{
	return s_strByDimAug.values();
}

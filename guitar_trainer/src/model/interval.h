#ifndef INTERVAL_H
#define INTERVAL_H

#include <QString>
#include <QHash>

namespace Model
{
	class Interval
	{
		public:
			enum EMinMajPerfect
			{
				PERFECT_UNISON,
				MINOR_SECOND,
				MAJOR_SECOND,
				MINOR_THIRD,
				MAJOR_THIRD,
				PERFECT_FOURTH,
				PERFECT_FIFTH,
				MINOR_SIXTH,
				MAJOR_SIXTH,
				MINOR_SEVENTH,
				MAJOR_SEVENTH,
				PERFECT_OCTAVE
			};

			enum EDimAug
			{
				DIMINISHED_SECOND,
				AUGMENTED_UNISON,
				DIMINISHED_THIRD,
				AUGMENTED_SECOND,
				DIMINISHED_FOURTH,
				AUGMENTED_THIRD,
				DIMINISHED_FIFTH,
				AUGMENTED_FOURTH,
				DIMINISHED_SIXTH,
				AUGMENTED_FIFTH,
				DIMINISHED_SEVENTH,
				AUGMENTED_SIXTH,
				DIMINISHED_OCTAVE,
				AUGMENTED_SEVENTH
			};

			static QString toString(EMinMajPerfect interval);
			static EMinMajPerfect toMinMajPerfect(const QString& intervalStr);
			static QStringList minMajPerfectIntervals();
			static QString toString(EDimAug interval);
			static EDimAug toDimAug(const QString& intervalStr);
			static QStringList dimAugIntervals();

		private:
			static QHash<EMinMajPerfect, QString> initStrByMinMajPerfect();
			static QHash<EDimAug, QString> initStrByDimAug();

		private:
			static const QHash<EMinMajPerfect, QString> s_strByMinMajPerfect;
			static const QHash<EDimAug, QString> s_strByDimAug;
	};

} // Model

#endif // INTERVAL_H

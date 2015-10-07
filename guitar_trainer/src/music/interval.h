#ifndef INTERVAL_H
#define INTERVAL_H

#include <QString>
#include <QHash>

namespace Music
{
	class Interval
	{
		public:
			enum EInterval
			{
				PERFECT_UNISON,
				MINOR_SECOND,
				MAJOR_SECOND,
				MINOR_THIRD,
				MAJOR_THIRD,
				PERFECT_FOURTH,
				DIMINISHED_FIFTH,
				PERFECT_FIFTH,
				MINOR_SIXTH,
				MAJOR_SIXTH,
				MINOR_SEVENTH,
				MAJOR_SEVENTH,
				PERFECT_OCTAVE,
				MINOR_NINTH,
				MAJOR_NINTH,
				MINOR_TENTH,
				MAJOR_TENTH,
				PERFECT_ELEVENTH,
				DIMINISHED_TWELFTH,
				PERFECT_TWELFTH,
				MINOR_THIRTEENTH,
				MAJOR_THIRTEENTH,
				MINOR_FOURTEENTH,
				MAJOR_FOURTEENTH,
				PERFECT_FIFTEENTH,
				AUGMENTED_FIFTEENTH
			};

			static QString toString(EInterval interval);
			static EInterval toInterval(const QString& intervalStr);
			static EInterval toInterval(const uint semiTone);
			static uint toSemiTone(EInterval interval);
			static QStringList intervals();

		private:
			static QHash<EInterval, QString> initStrByInterval();

		private:
			static const QHash<EInterval, QString> s_strByInterval;
	};

} // Music

#endif // INTERVAL_H

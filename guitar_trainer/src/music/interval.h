#ifndef INTERVAL_H
#define INTERVAL_H

#include "intervalqualification.h"

namespace Music
{
	class Interval
	{
		public:
			enum class Type
			{
				UNISON,
				SECOND,
				THIRD,
				FOURTH,
				FIFTH,
				SIXTH,
				SEVENTH,
				OCTAVE
			};

		public:
			static const QHash<Type, QString>& intervalShortNames();

		private:
			static QHash<Type, QString> initIntervalShortNames();
			static QHash<Type, QString> initIntervalFullNames();
			static QHash<Type, QList<IntervalQualification::Type>> initIntervalQualifications();

		private:
			static QHash<Type, QString> s_intervalShortNames;
			static QHash<Type, QString> s_intervalFullNames;
			static QHash<Type, QList<IntervalQualification::Type>> s_intervalQualifications;
	};

	inline uint qHash(const Interval::Type &key)
	{
			return static_cast<int>(key);
	}

} // Music

#endif // INTERVAL_H

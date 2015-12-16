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

		private:
			static QHash<Type, QString> initIntervalNames();
			static QHash<Type, QList<IntervalQualification::Type>> initIntervalQualifications();

		private:
			static QHash<Type, QString> s_intervalNames;
			static QHash<Type, QList<IntervalQualification::Type>> s_intervalQualifications;
	};

	inline uint qHash(const Interval::Type &key)
	{
			return static_cast<int>(key);
	}

} // Music

#endif // INTERVAL_H

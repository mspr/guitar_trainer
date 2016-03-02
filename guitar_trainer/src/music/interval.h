#ifndef INTERVAL_H
#define INTERVAL_H

#include <QHash>
#include <QMap>
#include <QString>

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
			static const QMap<Interval::Type, QStringList>& intervalQualifications();

		private:
			static QHash<Type, QString> initIntervalShortNames();
			static QHash<Type, QString> initIntervalFullNames();
			static QMap<Type, QStringList> initIntervalQualifications();

		private:
			static QHash<Type, QString> s_intervalShortNames;
			static QHash<Type, QString> s_intervalFullNames;
			static QMap<Type, QStringList> s_intervalQualifications;
	};

	inline uint qHash(const Interval::Type &key)
	{
			return static_cast<int>(key);
	}

} // Music

#endif // INTERVAL_H

#ifndef INTERVALQUALIFICATION_H
#define INTERVALQUALIFICATION_H

#include <QString>
#include <QHash>

namespace Music
{
	class IntervalQualification
	{
		public:
			enum class Type
			{
				DIMINISHED,
				MINOR,
				PERFECT,
				MAJOR,
				AUGMENTED
			};

		public:
			static QHash<Type, QString>& intervalQualifications();

		private:
			static QHash<Type, QString> initIntervalQualifications();

		private:
			static QHash<Type, QString> s_intervalQualifications;

		private:
			IntervalQualification() = delete;
	};

	inline uint qHash(const IntervalQualification::Type &key)
	{
			return static_cast<int>(key);
	}

} // Music

#endif // INTERVALQUALIFICATION_H

#ifndef INTERVALQUALIFICATION_H
#define INTERVALQUALIFICATION_H

#include <QString>

namespace Music
{
	class IntervalQualification
	{
		public:
			static QList<IntervalQualification>& intervalQualifications();

		private:
			static QList<IntervalQualification> initIntervalQualifications();
			static QList<IntervalQualification> s_intervalQualifications;

		public:
			enum class Type
			{
				DIMINISHED,
				MINOR,
				PERFECT,
				MAJOR,
				AUGMENTED
			};

			Type type() const;
			QString name() const;

		private:
			IntervalQualification(const Type type, const QString& name);

		private:
			Type m_type;
			QString m_name;
	};

} // Music

#endif // INTERVALQUALIFICATION_H

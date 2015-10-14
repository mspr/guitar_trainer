#ifndef FRETBOARDXMLREADER_H
#define FRETBOARDXMLREADER_H

#include <QObject>
#include <QHash>

namespace Fretboard
{
	class FretboardXmlReader : public QObject
	{
		public:
			FretboardXmlReader(QObject* parent = 0);

			bool handle(const QString& fileName);

			QString imagePath() const;
			QHash<uint, double> yByString() const;
			QHash<uint, double> xByFret() const;

		private:
			QString m_imagePath;
			QString m_tuning;
			QHash<uint, double> m_yByString;
			QHash<uint, double> m_xByFret;
	};

} // Fretboard

#endif // FRETBOARDXMLREADER_H

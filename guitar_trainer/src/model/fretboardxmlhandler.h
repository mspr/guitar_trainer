#ifndef FRETBOARDXMLHANDLER_H
#define FRETBOARDXMLHANDLER_H

#include <QObject>
#include <QHash>

namespace Model
{
	class FretboardXmlHandler : public QObject
	{
		public:
			FretboardXmlHandler(QObject* parent = 0);

			bool handle(const QString& fileName);

		private:
			QString m_tuning;
			uint m_stringCount;
			QHash<uint, double> m_yByString;
			uint m_fretCount;
			QHash<uint, double> m_xByFret;
	};

} // Model

#endif // FRETBOARDXMLHANDLER_H

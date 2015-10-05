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
			uint m_stringCount;
			QHash<uint, uint> m_yByString;
			uint m_fretCount;
			QHash<uint, uint> m_xByFret;
	};

} // Model

#endif // FRETBOARDXMLHANDLER_H

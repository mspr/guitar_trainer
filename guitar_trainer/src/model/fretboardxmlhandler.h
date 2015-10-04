#ifndef FRETBOARDXMLHANDLER_H
#define FRETBOARDXMLHANDLER_H

#include <QObject>

namespace Model
{
	class FretboardXmlHandler : public QObject
	{
		public:
			FretboardXmlHandler(QObject* parent = 0);

			bool handle(const QString& fileName);
	};

} // Model

#endif // FRETBOARDXMLHANDLER_H

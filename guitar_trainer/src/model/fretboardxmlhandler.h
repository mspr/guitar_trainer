#ifndef FRETBOARDXMLHANDLER_H
#define FRETBOARDXMLHANDLER_H

#include <QtXml/QXmlDefaultHandler>

namespace Model
{
	class FretboardXmlHandler : public QXmlDefaultHandler
	{
		public:
			FretboardXmlHandler();
	};

} // Model

#endif // FRETBOARDXMLHANDLER_H

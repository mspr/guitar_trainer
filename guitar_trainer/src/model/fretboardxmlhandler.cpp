#include "fretboardxmlhandler.h"

#include <QDomDocument>
#include <QFile>

using namespace Model;

FretboardXmlHandler::FretboardXmlHandler(QObject* parent)
	: QObject(parent)
{
}

bool FretboardXmlHandler::handle(const QString& fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QDomDocument dom;
		if (dom.setContent(file.readAll()))
		{
			const QDomElement rootElm = dom.firstChildElement("fretboard");
			if (!rootElm.isNull())
			{
				const QDomElement fretsElm = dom.firstChildElement("frets");
				if (!fretsElm.isNull())
				{
				}

				const QDomElement stringsElm = dom.firstChildElement("strings");
				if (!stringsElm.isNull())
				{
				}
			}
		}
	}

	return true;
}

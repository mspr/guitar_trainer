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
			const QDomElement fretboardElm = dom.firstChildElement("fretboard");
			if (!fretboardElm.isNull())
			{
				m_imagePath = fretboardElm.attribute("imagePath");
				m_tuning = fretboardElm.attribute("tuning");

				const QDomElement stringsElm = fretboardElm.firstChildElement("strings");
				if (!stringsElm.isNull())
				{
					const QDomNodeList stringNodeList = stringsElm.childNodes();
					for (int i=0; i<stringNodeList.count(); ++i)
					{
						const QDomElement stringElm = stringNodeList.at(i).firstChildElement("string");
						if (!stringElm.isNull())
						{
							const double y = stringElm.attribute("y").toDouble();
							m_yByString.insert(i, y);
						}
					}
				}

				const QDomElement fretsElm = fretboardElm.firstChildElement("frets");
				if (!fretsElm.isNull())
				{
					const QDomNodeList fretNodeList = fretsElm.childNodes();
					for (int i=0; i<fretNodeList.count(); ++i)
					{
						const QDomElement fretElm = fretNodeList.at(i).firstChildElement("fret");
						if (!fretElm.isNull())
						{
							const double x = fretElm.attribute("x").toDouble();
							m_xByFret.insert(i, x);
						}
					}
				}
			}
		}
	}

	return true;
}

QString FretboardXmlHandler::imagePath() const
{
	return m_imagePath;
}

QHash<uint, double> FretboardXmlHandler::yByString() const
{
	return m_yByString;
}

QHash<uint, double> FretboardXmlHandler::xByFret() const
{
	return m_xByFret;
}

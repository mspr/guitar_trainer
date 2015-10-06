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

				const QDomElement fretsElm = fretboardElm.firstChildElement("frets");
				if (!fretsElm.isNull())
				{
					const QDomNodeList fretNodeList = fretsElm.childNodes();
					m_fretCount = fretNodeList.count();

					for (uint i=0; i<m_fretCount; ++i)
					{
						const QDomElement fretElm = fretNodeList.at(i).firstChildElement("fret");
						if (!fretElm.isNull())
						{
							const double x = fretElm.attribute("x").toDouble();
							m_xByFret.insert(i, x);
						}
					}
				}

				const QDomElement stringsElm = fretboardElm.firstChildElement("strings");
				if (!stringsElm.isNull())
				{
					const QDomNodeList stringNodeList = stringsElm.childNodes();
					m_stringCount = stringNodeList.count();

					for (uint i=0; i<m_stringCount; ++i)
					{
						const QDomElement stringElm = stringNodeList.at(i).firstChildElement("string");
						if (!stringElm.isNull())
						{
							const double y = stringElm.attribute("y").toDouble();
							m_yByString.insert(i, y);
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

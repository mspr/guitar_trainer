#include "fretboardxmlwriter.h"

using namespace Fretboard;

FretboardXmlWriter::FretboardXmlWriter(QByteArray* buffer)
	: QXmlStreamWriter(buffer)
{
}

void FretboardXmlWriter::writeStartFretboard(const QString& fileName)
{
	writeStartDocument();
	writeStartElement("fretboard");
	writeAttribute("tuning", "EADGBE");
	writeAttribute("image", "");
}

void FretboardXmlWriter::writeEndFretboard()
{
	writeEndElement();
	writeEndDocument();
}

void FretboardXmlWriter::writeString(int y)
{

}

void FretboardXmlWriter::writeFret(int x)
{

}

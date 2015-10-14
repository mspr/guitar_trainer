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
	writeAttribute("imagePath", fileName);
	writeAttribute("tuning", "EADGBE");
}

void FretboardXmlWriter::writeEndFretboard()
{
	writeEndElement();
	writeEndDocument();
}

void FretboardXmlWriter::writeStartStrings()
{
	writeStartElement("strings");
}

void FretboardXmlWriter::writeString(double y)
{
	writeEmptyElement("string");
	writeAttribute("y", QString::number(y));
}

void FretboardXmlWriter::writeEndStrings()
{
	writeEndElement();
}

void FretboardXmlWriter::writeStartFrets()
{
	writeStartElement("frets");
}

void FretboardXmlWriter::writeFret(double x)
{
	writeEmptyElement("fret");
	writeAttribute("x", QString::number(x));
}

void FretboardXmlWriter::writeEndFrets()
{
	writeEndElement();
}

#ifndef FRETBOARDXMLWRITER_H
#define FRETBOARDXMLWRITER_H

#include <QXmlStreamWriter>

namespace Fretboard
{
	class FretboardXmlWriter : protected QXmlStreamWriter
	{
		public:
			FretboardXmlWriter(QByteArray* buffer);

			void writeStartFretboard(const QString& fileName);
			void writeEndFretboard();
			void writeStartStrings();
			void writeString(double y);
			void writeEndStrings();
			void writeStartFrets();
			void writeFret(double x);
			void writeEndFrets();
	};

} // Fretboard

#endif // FRETBOARDXMLWRITER_H

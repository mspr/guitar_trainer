#ifndef FRETBOARDXMLWRITER_H
#define FRETBOARDXMLWRITER_H

#include <QXmlStreamWriter>

namespace Fretboard
{
	class FretboardXmlWriter : public QXmlStreamWriter
	{
		public:
			FretboardXmlWriter(QByteArray* buffer);

			void writeStartFretboard(const QString& fileName);
			void writeEndFretboard();
			void writeString(int y);
			void writeFret(int x);
	};

} // Fretboard

#endif // FRETBOARDXMLWRITER_H

#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QHash>

namespace Model
{
	class Note
	{
		public:
			enum ENote
			{
				A,
				Ash,
				B,
				C,
				Csh,
				D,
				Dsh,
				E,
				F,
				Fsh,
				G,
				Gsh,
				NOTE_COUNT
			};

			static QString toString(ENote note);
			static ENote toNote(const QString& noteStr);
			static QStringList notes();

		private:
			static QHash<Note::ENote, QString> initMapStrByNote();

		private:
			static const QHash<ENote, QString> s_mapStrByNote;
	};

} // Model

#endif // NOTE_H

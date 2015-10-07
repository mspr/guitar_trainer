#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QHash>

namespace Music
{
	class Note
	{
		public:
			enum ENote
			{
				A,
				ASH,
				B,
				C,
				CSH,
				D,
				DSH,
				E,
				F,
				FSH,
				G,
				GSH,
				NOTE_COUNT
			};

			static QString toString(ENote note);
			static ENote toNote(const QString& noteStr);
			static QStringList notes();

		private:
			static QHash<Note::ENote, QString> initStrByNote();

		private:
			static const QHash<ENote, QString> s_strByNote;
	};

} // Music

#endif // NOTE_H

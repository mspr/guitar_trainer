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
				A_SHARP,
				B,
				C,
				C_SHARP,
				D,
				D_SHARP,
				E,
				F,
				F_SHARP,
				G,
				G_SHARP,
				NOTE_COUNT
			};

			static QString toString(ENote note);
			static ENote toNote(const QString& noteStr);
			static QStringList notes();
			static QList<ENote> tuning(const QString& tuningStr);
			static ENote getNoteFrom(const ENote fromNote, const uint semiToneNumber);

		private:
			static QHash<Note::ENote, QString> initStrByNote();

		private:
			static const QHash<ENote, QString> s_strByNote;
	};

} // Music

#endif // NOTE_H

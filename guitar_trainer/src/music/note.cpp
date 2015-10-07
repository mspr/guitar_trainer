#include "note.h"

#include <QStringList>

using namespace Music;

const QHash<Note::ENote, QString> Note::s_strByNote = Note::initStrByNote();

/*static*/ QHash<Note::ENote, QString> Note::initStrByNote()
{
	QHash<Note::ENote, QString> strByNote;

	strByNote.insert(Note::A, "A");
	strByNote.insert(Note::A_SHARP, "A#");
	strByNote.insert(Note::B, "B");
	strByNote.insert(Note::C, "C");
	strByNote.insert(Note::C_SHARP, "C#");
	strByNote.insert(Note::D, "D");
	strByNote.insert(Note::D_SHARP, "D#");
	strByNote.insert(Note::E, "E");
	strByNote.insert(Note::F, "F");
	strByNote.insert(Note::F_SHARP, "F#");
	strByNote.insert(Note::G, "G");
	strByNote.insert(Note::G_SHARP, "G#");

	return strByNote;
}

/*static*/ QString Note::toString(ENote note)
{
	return s_strByNote.value(note);
}

/*static*/ Note::ENote Note::toNote(const QString& noteStr)
{
	return s_strByNote.key(noteStr);
}

/*static*/ QStringList Note::notes()
{
	return s_strByNote.values();
}

#include "note.h"

#include <QStringList>

using namespace Model;

const QHash<Note::ENote, QString> Note::s_mapStrByNote = Note::initMapStrByNote();

/*static*/ QHash<Note::ENote, QString> Note::initMapStrByNote()
{
	QHash<Note::ENote, QString> mapStrByNote;

	mapStrByNote.insert(Note::A, "A");
	mapStrByNote.insert(Note::Ash, "A#");
	mapStrByNote.insert(Note::B, "B");
	mapStrByNote.insert(Note::C, "C");
	mapStrByNote.insert(Note::Csh, "C#");
	mapStrByNote.insert(Note::D, "D");
	mapStrByNote.insert(Note::Dsh, "D#");
	mapStrByNote.insert(Note::E, "E");
	mapStrByNote.insert(Note::F, "F");
	mapStrByNote.insert(Note::Fsh, "F#");
	mapStrByNote.insert(Note::G, "G");
	mapStrByNote.insert(Note::Gsh, "G#");

	return mapStrByNote;
}

/*static*/ QString Note::toString(ENote note)
{
	return s_mapStrByNote.value(note);
}

/*static*/ Note::ENote Note::toNote(const QString& noteStr)
{
	return s_mapStrByNote.key(noteStr);
}

/*static*/ QStringList Note::notes()
{
	return s_mapStrByNote.values();
}

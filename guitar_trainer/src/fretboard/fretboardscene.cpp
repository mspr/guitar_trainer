#include "fretboardscene.h"
#include "fretboardnote.h"

#include <QDebug>

using namespace Fretboard;
using namespace Music;

FretboardScene::FretboardScene(QObject* parent)
	: QGraphicsScene(parent)
{
}

FretboardScene::~FretboardScene()
{
	clear();
}

void FretboardScene::init(const QPixmap& imagePix,
													const QList<Music::Note::ENote>& tuning,
													const QHash<uint, double>& yByString,
													const QHash<uint, double>& xByFret)
{
	initBackground(imagePix);
	initTuning(tuning);
	initFretAndStringPositions(xByFret, yByString);
}

void FretboardScene::initBackground(const QPixmap& imagePix)
{
	addPixmap(imagePix);

	setSceneRect(imagePix.rect().x(),
							 imagePix.rect().y(),
							 imagePix.rect().x() + imagePix.rect().width(),
							 imagePix.rect().y() + imagePix.rect().height());
}

void FretboardScene::initTuning(const QList<Music::Note::ENote>& tuning)
{
	m_tuning = tuning;
}

void FretboardScene::initFretAndStringPositions(const QHash<uint, double>& xByFret,
																								const QHash<uint, double>& yByString)
{
	m_xByFret = xByFret;
	m_yByString = yByString;
}

bool FretboardScene::tryAddNote(const QPointF& pos)
{
	bool noteAdded = false;

	const QPair<uint, uint> fretboardPos = qMakePair(getNearestString(pos), getNearestFret(pos));
	if (m_noteByFretboardPos.find(fretboardPos) == m_noteByFretboardPos.end())
	{
		FretboardNote* note = new FretboardNote(getNote(fretboardPos));
		addItem(note);
		m_noteByFretboardPos.insert(fretboardPos, note);
		noteAdded = true;
	}
	else
		qWarning() << QString("A note already exist at fret %1 on string %2").arg(fretboardPos.second, fretboardPos.first);

	return noteAdded;
}

bool FretboardScene::tryRemoveNote(const QPointF& pos)
{
	bool noteRemoved = false;

	const QPair<uint, uint> fretboardPos = qMakePair(getNearestString(pos), getNearestFret(pos));
	const QHash<QPair<uint, uint>, FretboardNote*>::iterator it = m_noteByFretboardPos.find(fretboardPos);
	if (it != m_noteByFretboardPos.end())
	{
		delete it.value();
		m_noteByFretboardPos.erase(it);
		noteRemoved = true;
	}

	return noteRemoved;
}

uint FretboardScene::getNearestId(const QHash<uint, double>& posById, const double value) const
{
	uint nearestId;

	QHash<uint, double>::const_iterator it = posById.begin();
	int minDist = abs(value - it.value());
	nearestId = it.key();

	for (++it; it != posById.end(); ++it)
	{
		const int dist = abs(value - it.value());
		if (dist < minDist)
		{
			minDist = dist;
			nearestId = it.key();
		}
	}

	return nearestId;
}

uint FretboardScene::getNearestString(const QPointF& pos) const
{
	return getNearestId(m_yByString, pos.y());
}

uint FretboardScene::getNearestFret(const QPointF& pos) const
{
	return getNearestId(m_xByFret, pos.x());
}

Note::ENote FretboardScene::getNote(const QPair<uint, uint>& fretboardPos) const
{
	const Note::ENote openStringNote = m_tuning.at(fretboardPos.first);
	return Note::getNoteFrom(openStringNote, fretboardPos.second);
}

void FretboardScene::clear()
{
	clearNotes();
}

void FretboardScene::clearNotes()
{
	qDeleteAll(m_noteByFretboardPos); // TODO Check if it works
	m_noteByFretboardPos.clear();
}

#include "fretboardscene.h"

using namespace Fretboard;

FretboardScene::FretboardScene(QObject* parent)
	: QGraphicsScene(parent)
{
}

void FretboardScene::init(const QPixmap& imagePix,
													const QHash<uint, double>& yByString,
													const QHash<uint, double>& xByFret)
{
	initBackground(imagePix);
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

void FretboardScene::initFretAndStringPositions(const QHash<uint, double>& xByFret,
																								const QHash<uint, double>& yByString)
{
	m_xByFret = xByFret;
	m_yByString = yByString;
}

void FretboardScene::addNote(const QPointF& pos)
{
	const uint nearestFret = getNearestFret(pos);
	const uint nearestString = getNearestString(pos);



	//FretboardNote* note = new FretboardNote();
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

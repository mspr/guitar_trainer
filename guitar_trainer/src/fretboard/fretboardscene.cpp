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

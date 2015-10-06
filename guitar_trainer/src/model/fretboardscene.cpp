#include "fretboardscene.h"
#include "fretboardxmlhandler.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

using namespace Model;

FretboardScene::FretboardScene(QObject* parent)
	: QGraphicsScene(parent)
	, m_editionMode(FRET_EDITION)
{
}

void FretboardScene::init(const QString& fileName)
{
	FretboardXmlHandler xmlHandler;
	if (xmlHandler.handle(fileName))
	{
		const QString& imagePath = xmlHandler.imagePath();
		QPixmap pix;
		if (pix.load(imagePath))
		{
			addPixmap(pix);

			const QHash<uint, double> yByString = xmlHandler.yByString();
		}
		else
			qWarning() << QString("Impossible to load fretboard image %1.").arg(imagePath);
	}
}

void FretboardScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);

	if (event->button() == Qt::RightButton)
	{
		m_editionMode = (EditionMode)(((int)m_editionMode + 1) / 2);
	}
}

void FretboardScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);
}

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
	FretboardXmlHandler fretboardXmlHandler;
	if (fretboardXmlHandler.handle(fileName))
	{
		const QString& imagePath = fretboardXmlHandler.imagePath();
		QPixmap pix;
		if (pix.load(imagePath))
		{
			addPixmap(pix);
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

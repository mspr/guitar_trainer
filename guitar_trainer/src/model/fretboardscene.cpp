#include "fretboardscene.h"
#include "fretboardxmlhandler.h"

#include <QGraphicsSceneMouseEvent>

using namespace Model;

FretboardScene::FretboardScene(const QRectF& sceneRect, QObject* parent)
	: QGraphicsScene(sceneRect, parent)
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
		pix.load(imagePath);
		addPixmap(pix);
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

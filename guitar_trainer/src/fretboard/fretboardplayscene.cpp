#include "fretboardplayscene.h"

#include <QGraphicsSceneMouseEvent>

using namespace Fretboard;

FretboardPlayScene::FretboardPlayScene()
{
}

void FretboardPlayScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	FretboardScene::mousePressEvent(event);

	if (event->button() == Qt::LeftButton)
		tryAddNote(event->scenePos());
}

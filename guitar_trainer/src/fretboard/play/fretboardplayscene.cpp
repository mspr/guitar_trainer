#include "fretboardplayscene.h"

#include <QGraphicsSceneMouseEvent>

using namespace Fretboard;

FretboardPlayScene::FretboardPlayScene(QObject* parent)
	: FretboardScene(parent)
{
}

void FretboardPlayScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	FretboardScene::mousePressEvent(event);

	if (event->button() == Qt::LeftButton)
		tryAddNote(event->scenePos());
}

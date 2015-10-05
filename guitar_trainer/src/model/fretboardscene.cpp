#include "fretboardscene.h"
#include "fretboardxmlhandler.h"

using namespace Model;

FretboardScene::FretboardScene(const QRectF& sceneRect, QObject* parent)
	: QGraphicsScene(sceneRect, parent)
{
}

void FretboardScene::init(const QString& fileName)
{
	FretboardXmlHandler fretboardXmlHandler;
	const bool result = fretboardXmlHandler.handle(fileName);
}

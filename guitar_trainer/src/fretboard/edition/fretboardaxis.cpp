#include "fretboardaxis.h"
#include "fretboardeditscene.h"

using namespace Fretboard;

FretboardAxis::FretboardAxis(QGraphicsItem* parent)
	: QGraphicsLineItem(parent)
{
}

FretboardAxis::FretboardAxis(const QLineF& line, QGraphicsItem* parent)
	: QGraphicsLineItem(line, parent)
{
}

FretboardEditScene* FretboardAxis::getScene() const
{
	FretboardEditScene* scene = qobject_cast<FretboardEditScene*>(this->scene());
	Q_ASSERT_X(scene != nullptr, "getScene()", "nullptr");
	return scene;
}

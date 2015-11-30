#include "fretboardaxiseditor.h"
#include "fretboardeditscene.h"

using namespace Fretboard;

FretboardAxisEditor::FretboardAxisEditor(QGraphicsItem* parent)
	: FretboardAxis(parent)
{
}

FretboardAxisEditor::FretboardAxisEditor(const QLineF& line, QGraphicsItem* parent)
	: FretboardAxis(line, parent)
{
}

QVariant FretboardAxisEditor::itemChange(GraphicsItemChange change, const QVariant& value)
{
	if (change == ItemPositionChange)
	{
		QPointF newPos = value.toPointF();

		FretboardEditScene* scene = getScene();
		if (scene->isInFretMode())
			newPos.setY(scenePos().y());
		else if (scene->isInStringMode())
			newPos.setX(scenePos().x());

		return newPos;
	}

	return FretboardAxis::itemChange(change, value);
}

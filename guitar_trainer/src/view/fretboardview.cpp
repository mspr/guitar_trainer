#include "fretboardview.h"
#include "model/fretboardscene.h"

using namespace View;
using namespace Model;

FretboardView::FretboardView(QWidget* parent)
	: QGraphicsView(parent)
{
}

void FretboardView::initScene(const QString& fileName)
{
	FretboardScene* scene = dynamic_cast<FretboardScene*>(this->scene());
	Q_ASSERT_X(scene == nullptr, "initScene()", "nullptr");

	scene->init(fileName);
}

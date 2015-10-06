#include "fretboardview.h"
#include "model/fretboardscene.h"

using namespace View;
using namespace Model;

FretboardView::FretboardView(QWidget* parent)
	: QGraphicsView(parent)
	, m_scene(new FretboardScene())
{
	setScene(m_scene.data());
}

void FretboardView::initScene(const QString& fileName)
{
	m_scene->init(fileName);
}

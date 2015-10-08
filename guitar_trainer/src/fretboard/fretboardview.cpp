#include "fretboardview.h"
#include "fretboardscene.h"

#include <QMouseEvent>

using namespace Fretboard;

FretboardView::FretboardView(QWidget* parent)
	: QGraphicsView(parent)
	, m_scene(new FretboardScene())
{
	setScene(m_scene.data());
	setEnabled(false);
}

void FretboardView::initScene(const QString& fileName)
{
	m_scene->init(fileName);

	setMouseTracking(true);
	setEnabled(true);
}

#include "fretboardview.h"
#include "fretboardscene.h"

#include <QMouseEvent>
#include <QDebug>

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

	qWarning() << "sceneRect " << sceneRect();

	setMouseTracking(true);
	setEnabled(true);
}

void FretboardView::mousePressEvent(QMouseEvent* event)
{
	QGraphicsView::mousePressEvent(event);
}

void FretboardView::mouseMoveEvent(QMouseEvent* event)
{
	qWarning() << "VIEW mousePos " << event->pos();

	QGraphicsView::mouseMoveEvent(event);
}

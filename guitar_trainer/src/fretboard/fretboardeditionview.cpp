#include "fretboardeditionview.h"
#include "fretboardeditionscene.h"

#include <QDragMoveEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QDebug>

using namespace Fretboard;

FretboardEditionView::FretboardEditionView(QWidget* parent)
	: FretboardView(parent)
{
}

FretboardEditionView::~FretboardEditionView()
{
	if (scene() != nullptr)
		delete scene();
}

void FretboardEditionView::initScene(const QString& fileName)
{
	qDebug() << "initScene(" << fileName << ")";

	FretboardEditionScene* scene = new FretboardEditionScene(fileName);
	setScene(scene);
}

void FretboardEditionView::saveScene(const QString& fileName)
{
	FretboardEditionScene* scene = dynamic_cast<FretboardEditionScene*>(this->scene());
	Q_ASSERT_X(scene != nullptr, "saveScene()", "nullptr");
	scene->save(fileName);
}

void FretboardEditionView::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->urls().count() == 1)
	{
		const QString fileName = event->mimeData()->urls().first().toLocalFile();
		if (QFileInfo(fileName).suffix() == "xml")
			event->acceptProposedAction();
	}

	QGraphicsView::dragEnterEvent(event);
}

void FretboardEditionView::dropEvent(QDropEvent* event)
{
	Q_ASSERT_X(event->mimeData()->urls().count() == 1, "dropEvent()", "");

	const QString fileName = event->mimeData()->urls().first().toLocalFile();
	if (QFileInfo(fileName).suffix() == "xml")
		initScene(fileName);

	QGraphicsView::dropEvent(event);
}

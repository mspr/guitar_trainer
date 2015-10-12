#include "fretboardeditionview.h"
#include "fretboardeditionscene.h"

#include <QDragMoveEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QDebug>

using namespace Fretboard;

FretboardEditionView::FretboardEditionView(QWidget* parent)
	: FretboardView(parent)
	, m_scene(new FretboardEditionScene())
{
	setScene(m_scene.data());
}

void FretboardEditionView::initScene(const QString& fileName)
{
	m_scene->init(fileName);
}

void FretboardEditionView::saveScene(const QString& fileName)
{
	m_scene->save(fileName);
}

void FretboardEditionView::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		foreach (const QUrl& url, event->mimeData()->urls())
		{
			qWarning() << "dragEnterEvent url " << url;

			const QString str = url.toLocalFile();
			qWarning() << "local file " << str;

			if (QFileInfo(str).suffix() == "xml")
			{
				qWarning() << "xml >> accepted drop action";
				event->acceptProposedAction();
			}
		}
	}

	QGraphicsView::dragEnterEvent(event);
}

void FretboardEditionView::dragMoveEvent(QDragMoveEvent* event)
{
	if (event->mimeData()->hasUrls())
	{
		foreach (const QUrl& url, event->mimeData()->urls())
		{
			qWarning() << "dragMoveEvent url " << url;

			const QString str = url.toLocalFile();
			qWarning() << "local file " << str;

			if (QFileInfo(str).suffix() == "xml")
			{
				qWarning() << "xml >> accepted drop action";
				event->acceptProposedAction();
			}
		}
	}

	QGraphicsView::dragMoveEvent(event);
}

void FretboardEditionView::dropEvent(QDropEvent* event)
{
	QGraphicsView::dropEvent(event);
}

#include "fretboardscene.h"
#include "fretboardxmlhandler.h"
#include "fretboardaxis.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QDebug>

using namespace Fretboard;

FretboardScene::FretboardScene(QObject* parent)
	: QGraphicsScene(parent)
	, m_editionMode(FRET_EDITION)
{
}

void FretboardScene::init(const QString& fileName)
{
	FretboardXmlHandler xmlHandler;
	if (xmlHandler.handle(fileName))
	{
		const QString& imagePath = xmlHandler.imagePath();
		QPixmap pix;
		if (pix.load(imagePath))
		{
			addPixmap(pix);
			setSceneRect(pix.rect().x(), pix.rect().y(), pix.rect().x() + pix.rect().width(), pix.rect().y() + pix.rect().height());

			const QHash<uint, double> yByString = xmlHandler.yByString();
			QHash<uint, double>::const_iterator it = yByString.begin();
			for (; it != yByString.end(); ++it)
			{
				addItem(new FretboardAxis(sceneRect().x(), it.value(),
																	sceneRect().x() + sceneRect().width(), it.value()));
			}

			const QHash<uint, double> xByFret = xmlHandler.xByFret();
			it = xByFret.begin();
			for (; it != xByFret.end(); ++it)
			{
				addItem(new FretboardAxis(it.value(), sceneRect().y(),
																	it.value(), sceneRect().y() + sceneRect().height()));
			}

			m_editionAxis = new FretboardAxis(sceneRect().x(), sceneRect().y(), sceneRect().x(), sceneRect().y() + sceneRect().height());
			addItem(m_editionAxis);
		}
		else
			qWarning() << QString("Impossible to load fretboard image %1.").arg(imagePath);
	}
}

void FretboardScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);

	if (event->button() == Qt::RightButton)
	{
		//m_editionMode = (EditionMode)(((int)m_editionMode + 1) / 2);

		//m_editionAxis->setRotation(90.0);
	}
	else
	{

	}
}

void FretboardScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);

	qWarning() << "SCENE mousePos " << event->scenePos() << " | sceneRect " << sceneRect() << " | axisPos " << m_editionAxis->pos();

	switch (m_editionMode)
	{
		case FRET_EDITION:
			m_editionAxis->setPos(event->scenePos().x(), sceneRect().y());
		break;
		case STRING_EDITION:
			m_editionAxis->setPos(sceneRect().x(), event->scenePos().y());
		break;
		default:
		break;
	}
}

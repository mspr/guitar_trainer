#include "fretboardeditionscene.h"
#include "fretboardxmlreader.h"
#include "fretboardxmlwriter.h"
#include "fretboardaxis.h"

#include <QGraphicsSceneMouseEvent>
#include <QFile>
#include <QDebug>

using namespace Fretboard;

FretboardEditionScene::FretboardEditionScene(QObject* parent)
	: FretboardScene(parent)
	, m_editionMode(FRET_EDITION)
{
}

FretboardEditionScene::FretboardEditionScene(const QString& imagePath,
																						 const QPixmap& imagePix,
																						 const QHash<uint, double>& yByString,
																						 const QHash<uint, double>& xByFret,
																						 QObject* parent)
	: FretboardScene(parent)
	, m_imagePath(imagePath)
{
	addPixmap(imagePix);

	setSceneRect(imagePix.rect().x(),
							 imagePix.rect().y(),
							 imagePix.rect().x() + imagePix.rect().width(),
							 imagePix.rect().y() + imagePix.rect().height());

	QHash<uint, double>::const_iterator it = yByString.begin();
	for (; it != yByString.end(); ++it)
	{
		FretboardAxis* axis = new FretboardAxis(sceneRect().x(), it.value(), sceneRect().x() + sceneRect().width(), it.value());
		addItem(axis);
		m_stringAxis.append(axis);
	}

	it = xByFret.begin();
	for (; it != xByFret.end(); ++it)
	{
		FretboardAxis* axis = new FretboardAxis(it.value(), sceneRect().y(), it.value(), sceneRect().y() + sceneRect().height());
		addItem(axis);
		m_fretAxis.append(axis);
	}

	m_editionAxis = new FretboardAxis(sceneRect().x(), sceneRect().y(), sceneRect().x(), sceneRect().y() + sceneRect().height());
	addItem(m_editionAxis);
}

/*static*/ FretboardEditionScene* FretboardEditionScene::tryLoad(const QString& fileName)
{
	FretboardEditionScene* scene = nullptr;

	FretboardXmlReader xmlReader;
	if (xmlReader.handle(fileName))
	{
		QPixmap pix;
		if (pix.load(xmlReader.imagePath()))
		{
			scene = new FretboardEditionScene(xmlReader.imagePath(),
																				pix,
																				xmlReader.yByString(),
																				xmlReader.xByFret());
		}
		else
			qWarning() << QString("Impossible to load fretboard image %1.").arg(xmlReader.imagePath());
	}

	return scene;
}

void FretboardEditionScene::save(const QString& fileName)
{
	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QByteArray buffer;
		FretboardXmlWriter writer(&buffer);
		writer.writeStartFretboard(m_imagePath);

		writer.writeStartStrings();
		foreach (const QGraphicsItem* axis, m_stringAxis)
			writer.writeString(axis->y());
		writer.writeEndStrings();

		writer.writeStartFrets();
		foreach (const QGraphicsItem* axis, m_fretAxis)
			writer.writeFret(axis->x());
		writer.writeEndFrets();

		writer.writeEndFretboard();

		file.write(buffer);
		file.close();
	}
}

void FretboardEditionScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mousePressEvent(event);

	if (event->button() == Qt::RightButton)
	{
		switchEditionMode(event->scenePos());
	}
	else
	{
		FretboardAxis* axis = new FretboardAxis(m_editionAxis->scenePos(), m_editionAxis->line());
		addItem(axis);

		if (m_editionMode == FRET_EDITION)
		{
			m_fretAxis.append(axis);
		}
		else // STRING_EDITION
		{
			m_stringAxis.append(axis);
		}
	}
}

void FretboardEditionScene::switchEditionMode(const QPointF& scenePos)
{
	if (m_editionMode == FRET_EDITION)
	{
		QPointF p1(sceneRect().x(), scenePos.y());
		m_editionAxis->setPos(p1);
		QPointF p2(sceneRect().x() + sceneRect().width(), 0);
		m_editionAxis->setLine(QLineF(QPointF(0,0), p2));
		m_editionMode = STRING_EDITION;
	}
	else // STRING_EDITION
	{
		QPointF p1(scenePos.x(), sceneRect().y());
		m_editionAxis->setPos(p1);
		QPointF p2(0, sceneRect().y() + sceneRect().height());
		m_editionAxis->setLine(QLineF(QPointF(0,0), p2));
		m_editionMode = FRET_EDITION;
	}
}

void FretboardEditionScene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	QGraphicsScene::mouseMoveEvent(event);

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

#include "fretboardeditionscene.h"
#include "fretboardxmlparser.h"
#include "fretboardxmlwriter.h"
#include "fretboardaxis.h"
#include "exception.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QFile>
#include <QDebug>

using namespace Fretboard;

FretboardEditionScene::FretboardEditionScene(const QString& fileName, QObject* parent)
	: FretboardScene(parent)
	, m_editionMode(FRET_EDITION)
{
	FretboardXmlParser xmlParser;
	if (xmlParser.handle(fileName))
	{
		m_imagePath = xmlParser.imagePath();
		QPixmap pix;

		try
		{
			if (pix.load(m_imagePath))
			{
				addPixmap(pix);
				setSceneRect(pix.rect().x(), pix.rect().y(), pix.rect().x() + pix.rect().width(), pix.rect().y() + pix.rect().height());

				const QHash<uint, double> yByString = xmlParser.yByString();
				QHash<uint, double>::const_iterator it = yByString.begin();
				for (; it != yByString.end(); ++it)
				{
					FretboardAxis* axis = new FretboardAxis(sceneRect().x(), it.value(), sceneRect().x() + sceneRect().width(), it.value());
					addItem(axis);
					m_stringAxis.append(axis);
				}

				const QHash<uint, double> xByFret = xmlParser.xByFret();
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
			else
			{
				throw Exception(QString("Impossible to load fretboard image %1.").arg(m_imagePath));
			}
		}
		catch(const Exception& e)
		{
			qWarning() << e.message();

			throw;
		}
	}
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

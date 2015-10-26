#include "fretboardeditionscene.h"
#include "fretboardxmlreader.h"
#include "fretboardxmlwriter.h"
#include "fretboardaxis.h"
#include "commandaddaxis.h"

#include <QGraphicsSceneMouseEvent>
#include <QUndoStack>
#include <QFile>
#include <QDebug>

using namespace Fretboard;

FretboardEditionScene::FretboardEditionScene(const QString& imagePath,
																						 const QPixmap& imagePix,
																						 const QHash<uint, double>& yByString,
																						 const QHash<uint, double>& xByFret,
																						 QObject* parent)
	: FretboardScene(parent)
	, m_usageMode(SELECTION_MODE)
	, m_imagePath(imagePath)
	, m_undoStack(new QUndoStack(this))
{
	addPixmap(imagePix);

	setSceneRect(imagePix.rect().x(),
							 imagePix.rect().y(),
							 imagePix.rect().x() + imagePix.rect().width(),
							 imagePix.rect().y() + imagePix.rect().height());

	QHash<uint, double>::const_iterator it = yByString.begin();
	for (; it != yByString.end(); ++it)
	{
		FretboardAxis* axis = new FretboardAxis(QLineF(0, 0, sceneRect().width(), 0));
		axis->setPos(sceneRect().x(), it.value());
		addItem(axis);
		m_stringAxis.append(axis);
	}

	it = xByFret.begin();
	for (; it != xByFret.end(); ++it)
	{
		FretboardAxis* axis = new FretboardAxis(QLineF(0, 0, 0, sceneRect().height()));
		axis->setPos(it.value(), sceneRect().y());
		addItem(axis);
		m_fretAxis.append(axis);
	}

	m_editionAxis = new FretboardAxis(QLineF(0, 0, 0, sceneRect().height()));
	m_editionAxis->setPos(sceneRect().x(), sceneRect().y());

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

void FretboardEditionScene::switchToSelectionMode()
{
	m_usageMode = SELECTION_MODE;
}

void FretboardEditionScene::switchToEditionMode()
{
	m_usageMode = EDITION_MODE;
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

		qWarning() << "Scene saved in " << fileName;
	}
}

void FretboardEditionScene::addAxis(FretboardAxis* axis)
{
	Q_ASSERT_X(axis != nullptr, "addAxis()", "nullptr");

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

void FretboardEditionScene::removeAxis(FretboardAxis* axis)
{
	Q_ASSERT_X(axis != nullptr, "removeAxis()", "nullptr");

	if (!m_fretAxis.removeOne(axis))
		m_stringAxis.removeOne(axis);

	removeItem(axis);

	delete axis;
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
		Q_ASSERT_X(m_undoStack != nullptr, "mousePressEvent()", "nullptr");
		m_undoStack->push(new CommandAddAxis(m_editionAxis->scenePos(), m_editionAxis->line(), this));
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

#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace Model
{
	class FretboardScene : public QGraphicsScene
	{
		enum EditionMode
		{
			FRET_EDITION,
			STRING_EDITION
		};

		public:
			FretboardScene(const QRectF& sceneRect, QObject* parent);

			void init(const QString& fileName);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

		private:
			EditionMode m_editionMode;
	};

} // Model

#endif // FRETBOARDSCENE_H

#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace Fretboard
{
	class FretboardAxis;

	class FretboardScene : public QGraphicsScene
	{
		enum EditionMode
		{
			FRET_EDITION,
			STRING_EDITION
		};

		public:
			FretboardScene(QObject* parent = 0);

			void init(const QString& fileName);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

		private:
			void switchEditionMode(const QPointF& scenePos);

		private:
			EditionMode m_editionMode;
			FretboardAxis* m_editionAxis;
	};

} // Fretboard

#endif // FRETBOARDSCENE_H

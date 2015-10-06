#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace View { class FretboardAxis; }

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
			FretboardScene(QObject* parent = 0);

			void init(const QString& fileName);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

		private:
			EditionMode m_editionMode;
			QPointF m_oldPos;
			View::FretboardAxis* m_editionAxis;
	};

} // Model

#endif // FRETBOARDSCENE_H

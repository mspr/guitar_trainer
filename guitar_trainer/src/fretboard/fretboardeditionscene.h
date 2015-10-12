#ifndef FRETBOARDEDITIONSCENE_H
#define FRETBOARDEDITIONSCENE_H

#include "fretboardscene.h"

namespace Fretboard
{
	class FretboardAxis;

	class FretboardEditionScene : public FretboardScene
	{
		enum EditionMode
		{
			FRET_EDITION,
			STRING_EDITION
		};

		public:
			FretboardEditionScene(QObject* parent = 0);

			void init(const QString& fileName);
			void save(const QString& fileName);

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

#endif // FRETBOARDEDITIONSCENE_H

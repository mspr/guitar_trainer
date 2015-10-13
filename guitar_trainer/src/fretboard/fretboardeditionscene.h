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
			FretboardEditionScene(const QString& fileName, QObject* parent = 0);

			void save(const QString& fileName);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

		private:
			void switchEditionMode(const QPointF& scenePos);

		private:
			EditionMode m_editionMode;
			FretboardAxis* m_editionAxis;
			QString m_imagePath;
			QList<FretboardAxis*> m_stringAxis;
			QList<FretboardAxis*> m_fretAxis;
	};

} // Fretboard

#endif // FRETBOARDEDITIONSCENE_H

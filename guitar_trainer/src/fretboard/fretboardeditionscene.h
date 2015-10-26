#ifndef FRETBOARDEDITIONSCENE_H
#define FRETBOARDEDITIONSCENE_H

#include "fretboardscene.h"

class QUndoStack;

namespace Fretboard
{
	class FretboardAxis;

	class FretboardEditionScene : public FretboardScene
	{
		Q_OBJECT

		enum UsageMode
		{
			SELECTION_MODE,
			EDITION_MODE
		};

		enum EditionMode
		{
			FRET_EDITION,
			STRING_EDITION
		};

		public:
			FretboardEditionScene(const QString& imagePath,
														const QPixmap& imagePix,
														const QHash<uint, double>& yByString,
														const QHash<uint, double>& xByFret,
														QObject* parent = 0);

			static FretboardEditionScene* tryLoad(const QString& fileName);
			void save(const QString& fileName);

			void switchToSelectionMode();
			void switchToEditionMode();

			void addAxis(FretboardAxis* axis);
			void removeAxis(FretboardAxis* axis);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

		private:
			void switchEditionMode(const QPointF& scenePos);

		private:
			UsageMode m_usageMode;
			EditionMode m_editionMode;
			FretboardAxis* m_editionAxis;
			QString m_imagePath;
			QList<FretboardAxis*> m_stringAxis;
			QList<FretboardAxis*> m_fretAxis;
			QUndoStack* m_undoStack;
	};

} // Fretboard

#endif // FRETBOARDEDITIONSCENE_H

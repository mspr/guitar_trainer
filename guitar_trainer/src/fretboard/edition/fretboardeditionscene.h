#ifndef FRETBOARDEDITIONSCENE_H
#define FRETBOARDEDITIONSCENE_H

#include "fretboard/fretboardscene.h"
#include "fretboardaxis.h"

class QUndoStack;

namespace Fretboard
{
	class FretboardEditionScene : public FretboardScene
	{
		Q_OBJECT

		private:
			enum class UsageMode
			{
				SELECTION,
				EDITION
			};

			enum class AxisType
			{
				FRET,
				STRING,
				ALL
			};

		public:
			enum class EditionMode
			{
				FRET,
				STRING
			};

		public:
			FretboardEditionScene(const QString& imagePath, QObject* parent = 0);

			static FretboardEditionScene* tryCreate(const QString& fileName);
			void save(const QString& fileName);

			void switchToSelectionMode();
			void switchToEditionMode();
			EditionMode editionMode() const;
			bool isInSelectionMode() const;
			bool isInFretMode() const;
			bool isInStringMode() const;

			void addFret(FretboardAxis* fret);
			void addString(FretboardAxis* string);
			void removeAxis(FretboardAxis* axis);
			void removeFret(FretboardAxis* fret);
			void removeString(FretboardAxis* string);

			QList<FretboardAxis*> selectedAxes() const;
			QList<FretboardAxis*> selectedFrets() const;
			QList<FretboardAxis*> selectedStrings() const;

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void keyPressEvent(QKeyEvent* event) override;

		private:
			void init(const QPixmap& imagePix,
								const QHash<uint, double>& yByString,
								const QHash<uint, double>& xByFret);

			void activateAxisMarker();

			void setAxesMovable(const bool movable);
			void switchToFretMode(const QPointF& scenePos);
			void switchToStringMode(const QPointF& scenePos);

			QList<FretboardAxis*> selectedAxes(const AxisType axisType) const;

			void mousePressEdition(QGraphicsSceneMouseEvent* event);
			void mouseMoveEdition(QGraphicsSceneMouseEvent* event);
			void mousePressSelection(QGraphicsSceneMouseEvent* event);
			void mouseMoveSelection(QGraphicsSceneMouseEvent* event);

		private:
			UsageMode m_usageMode;
			EditionMode m_editionMode;
			QScopedPointer<FretboardAxis> m_axisMarker;
			QString m_imagePath;
			QList<FretboardAxis*> m_stringAxis;
			QList<FretboardAxis*> m_fretAxis;
			QUndoStack* m_undoStack;
	};

} // Fretboard

#endif // FRETBOARDEDITIONSCENE_H

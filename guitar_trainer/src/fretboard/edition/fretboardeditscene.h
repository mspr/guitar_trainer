#ifndef FRETBOARDEDITSCENE_H
#define FRETBOARDEDITSCENE_H

#include "fretboard/fretboardscene.h"
#include "fretboardaxiseditor.h"

class QUndoStack;

namespace Fretboard
{
	class FretboardAxisEditable;
	class FretboardAxisFret;
	class FretboardAxisString;

	class FretboardEditScene : public FretboardScene
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
			FretboardEditScene(const QString& imagePath, QObject* parent = 0);
			virtual ~FretboardEditScene() override;

			static FretboardEditScene* tryCreate(const QString& fileName);
			void save(const QString& fileName);

			void switchToSelectionMode();
			void switchToEditionMode();
			EditionMode editionMode() const;
			bool isInSelectionMode() const;
			bool isInFretMode() const;
			bool isInStringMode() const;

			void addFret(FretboardAxisFret* fret);
			void addString(FretboardAxisString* string);
			void removeFret(FretboardAxisFret* fret);
			void removeString(FretboardAxisString* string);

			template <typename T>
			QList<T*> selectedAxes() const;
			QList<FretboardAxisFret*> selectedFrets() const;
			QList<FretboardAxisString*> selectedStrings() const;

		signals:
			void modified(bool modified);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void keyPressEvent(QKeyEvent* event) override;

			virtual void clear() override;

		private:
			virtual void init(const QPixmap& imagePix,
												const QList<Music::Note::ENote>& tuning,
												const QHash<uint, double>& yByString,
												const QHash<uint, double>& xByFret) override;

			void initCommandStack();
			void initAxes();

			void activateAxisEditor();

			void setAxesMovable(const bool movable);
			void switchToFretMode(const QPointF& scenePos);
			void switchToStringMode(const QPointF& scenePos);

			QList<FretboardAxisEditable*> selectedAxes(const AxisType axisType) const;

			void clearAxes();

			void mousePressEdition(QGraphicsSceneMouseEvent* event);
			void mouseMoveEdition(QGraphicsSceneMouseEvent* event);
			void mousePressSelection(QGraphicsSceneMouseEvent* event);
			void mouseMoveSelection(QGraphicsSceneMouseEvent* event);

		private slots:
			void onCleanChanged(bool clean);

		private:
			UsageMode m_usageMode;
			EditionMode m_editionMode;
			QScopedPointer<FretboardAxisEditor> m_axisEditor;
			QScopedPointer<QUndoStack> m_undoStack;
			QString m_imagePath;
			QList<FretboardAxisString*> m_stringAxes;
			QList<FretboardAxisFret*> m_fretAxes;
	};

} // Fretboard

#endif // FRETBOARDEDITSCENE_H

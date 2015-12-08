#ifndef FRETBOARDAXISBUILDER_H
#define FRETBOARDAXISBUILDER_H

#include <QScopedPointer>
#include <QPointF>
#include <QLineF>

namespace Fretboard
{
	class FretboardEditScene;
	class FretboardAxisString;
	class FretboardAxisFret;

	class FretboardAxisBuilder
	{
		public:
			FretboardAxisBuilder(FretboardEditScene* scene);

			void activate();
			void deactivate();
			void move(const QPointF& scenePos);
			void switchToFretMode(const QPointF& scenePos);
			void switchToStringMode(const QPointF& scenePos);

			FretboardAxisFret* buildFretFromMarker() const;
			FretboardAxisFret* buildFret(const QLineF& line, const QPointF& scenePos) const;
			FretboardAxisString* buildStringFromMarker() const;
			FretboardAxisString* buildString(const QLineF& line, const QPointF& scenePos) const;

		private:
			void initMarkers();

		private:
			FretboardEditScene* m_scene;
			QScopedPointer<FretboardAxisString> m_stringMarker;
			QScopedPointer<FretboardAxisFret> m_fretMarker;
	};

} // Fretboard

#endif // FRETBOARDAXISBUILDER_H

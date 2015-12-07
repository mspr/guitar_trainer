#ifndef FRETBOARDAXISBUILDER_H
#define FRETBOARDAXISBUILDER_H

#include <QScopedPointer>
#include <QPointF>

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

			FretboardAxisFret* buildFret() const;
			FretboardAxisString* buildString() const;

		private:
			void initMarkers();

		private:
			FretboardEditScene* m_scene;
			QScopedPointer<FretboardAxisString> m_stringMarker;
			QScopedPointer<FretboardAxisFret> m_fretMarker;
	};

} // Fretboard

#endif // FRETBOARDAXISBUILDER_H

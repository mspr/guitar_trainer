#ifndef FRETBOARDVIEW_H
#define FRETBOARDVIEW_H

#include <QGraphicsView>

namespace Fretboard
{
	class FretboardScene;

	class FretboardView : public QGraphicsView
	{
		public:
			FretboardView(QWidget* parent);

			void initScene(const QString& fileName);
			void saveScene(const QString& fileName);

		private:
			QScopedPointer<FretboardScene> m_scene;
	};

} // Fretboard

#endif // FRETBOARDVIEW_H

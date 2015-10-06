#ifndef FRETBOARDVIEW_H
#define FRETBOARDVIEW_H

#include <QGraphicsView>

namespace Model { class FretboardScene; }

namespace View
{
	class FretboardView : public QGraphicsView
	{
		public:
			FretboardView(QWidget* parent);

			void initScene(const QString& fileName);

		private:
			QScopedPointer<Model::FretboardScene> m_scene;
	};

} // Model

#endif // FRETBOARDVIEW_H

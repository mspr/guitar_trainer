#ifndef FRETBOARDVIEW_H
#define FRETBOARDVIEW_H

#include <QGraphicsView>

namespace View
{
	class FretboardView : public QGraphicsView
	{
		public:
			FretboardView(QWidget* parent);

			void initScene(const QString& fileName);
	};

} // Model

#endif // FRETBOARDVIEW_H

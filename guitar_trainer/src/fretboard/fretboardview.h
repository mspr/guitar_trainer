#ifndef FRETBOARDVIEW_H
#define FRETBOARDVIEW_H

#include <QGraphicsView>

namespace Fretboard
{
	class FretboardView : public QGraphicsView
	{
		public:
			FretboardView(QWidget* parent);

			virtual void initScene(const QString& fileName) = 0;
			virtual void saveScene(const QString& fileName) = 0;
	};

} // Fretboard

#endif // FRETBOARDVIEW_H

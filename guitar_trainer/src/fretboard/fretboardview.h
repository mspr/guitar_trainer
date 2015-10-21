#ifndef FRETBOARDVIEW_H
#define FRETBOARDVIEW_H

#include <QGraphicsView>

namespace Fretboard
{
	class FretboardView : public QGraphicsView
	{
		public:
			FretboardView(QWidget* parent);
	};

} // Fretboard

#endif // FRETBOARDVIEW_H

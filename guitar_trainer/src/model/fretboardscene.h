#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace View
{
	class FretboardScene : public QGraphicsScene
	{
		public:
			FretboardScene(const QRectF& sceneRect, QObject* parent);
	};

} // View

#endif // FRETBOARDSCENE_H

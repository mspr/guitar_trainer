#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace Model
{
	class FretboardScene : public QGraphicsScene
	{
		public:
			FretboardScene(const QRectF& sceneRect, QObject* parent);

			void init(const QString& fileName);
	};

} // Model

#endif // FRETBOARDSCENE_H

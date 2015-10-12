#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace Fretboard
{
	class FretboardScene : public QGraphicsScene
	{
		public:
			FretboardScene(QObject* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDSCENE_H

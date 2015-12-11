#ifndef FRETBOARDPLAYSCENE_H
#define FRETBOARDPLAYSCENE_H

#include "fretboard/fretboardscene.h"

namespace Fretboard
{
	class FretboardPlayScene : public FretboardScene
	{
		public:
			FretboardPlayScene(QObject* parent = 0);

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	};

} // Fretboard

#endif // FRETBOARDPLAYSCENE_H

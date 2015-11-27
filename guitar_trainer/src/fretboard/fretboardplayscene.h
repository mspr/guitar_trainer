#ifndef FRETBOARDPLAYSCENE_H
#define FRETBOARDPLAYSCENE_H

#include "fretboardscene.h"

namespace Fretboard
{
	class FretboardPlayScene : public FretboardScene
	{
		public:
			FretboardPlayScene();

		protected:
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	};

} // Fretboard

#endif // FRETBOARDPLAYSCENE_H

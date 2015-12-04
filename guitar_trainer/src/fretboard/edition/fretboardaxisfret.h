#ifndef FRETBOARDAXISFRET_H
#define FRETBOARDAXISFRET_H

#include "fretboardaxiseditable.h"

namespace Fretboard
{
	class FretboardAxisFret : public FretboardAxisEditable
	{
		public:
			FretboardAxisFret(QGraphicsItem* parent = 0);
			FretboardAxisFret(const QLineF& line, QGraphicsItem* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDAXISFRET_H

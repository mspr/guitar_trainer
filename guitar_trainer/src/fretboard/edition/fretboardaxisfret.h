#ifndef FRETBOARDAXISFRET_H
#define FRETBOARDAXISFRET_H

#include "fretboardaxis.h"

namespace Fretboard
{
	class FretboardAxisFret : public FretboardAxis
	{
		public:
			FretboardAxisFret(QGraphicsItem* parent = 0);
			FretboardAxisFret(const QLineF& line, QGraphicsItem* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDAXISFRET_H

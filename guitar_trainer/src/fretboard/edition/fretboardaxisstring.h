#ifndef FRETBOARDAXISSTRING_H
#define FRETBOARDAXISSTRING_H

#include "fretboardaxis.h"

namespace Fretboard
{
	class FretboardAxisString : public FretboardAxis
	{
		public:
			FretboardAxisString(QGraphicsItem* parent = 0);
			FretboardAxisString(const QLineF& line, QGraphicsItem* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDAXISSTRING_H

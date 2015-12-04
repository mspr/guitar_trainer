#ifndef FRETBOARDAXISSTRING_H
#define FRETBOARDAXISSTRING_H

#include "fretboardaxiseditable.h"

namespace Fretboard
{
	class FretboardAxisString : public FretboardAxisEditable
	{
		public:
			FretboardAxisString(QGraphicsItem* parent = 0);
			FretboardAxisString(const QLineF& line, QGraphicsItem* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDAXISSTRING_H

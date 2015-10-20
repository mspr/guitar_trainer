#ifndef FRETBOARDAXIS_H
#define FRETBOARDAXIS_H

#include <QGraphicsLineItem>

namespace Fretboard
{
	class FretboardAxis : public QGraphicsLineItem
	{
		public:
			FretboardAxis(const QLineF& line, QGraphicsItem* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDAXIS_H

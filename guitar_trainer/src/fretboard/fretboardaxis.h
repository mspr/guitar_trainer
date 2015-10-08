#ifndef FRETBOARDAXIS_H
#define FRETBOARDAXIS_H

#include <QGraphicsLineItem>

namespace Fretboard
{
	class FretboardAxis : public QGraphicsLineItem
	{
		public:
			FretboardAxis(qreal x1, qreal y1, qreal x2, qreal y2, QGraphicsItem* parent = 0);
	};

} // Fretboard

#endif // FRETBOARDAXIS_H

#ifndef FRETBOARDAXIS_H
#define FRETBOARDAXIS_H

#include <QGraphicsLineItem>

namespace View
{
	class FretboardAxis : public QGraphicsLineItem
	{
		public:
			FretboardAxis(QGraphicsItem* parent);
	};

} // View

#endif // FRETBOARDAXIS_H

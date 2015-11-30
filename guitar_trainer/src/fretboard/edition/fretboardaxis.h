#ifndef FRETBOARDAXIS_H
#define FRETBOARDAXIS_H

#include <QGraphicsLineItem>

namespace Fretboard
{
	class FretboardEditScene;

	class FretboardAxis : public QGraphicsLineItem
	{
		public:
			FretboardAxis(QGraphicsItem* parent = 0);
			FretboardAxis(const QLineF& line, QGraphicsItem* parent = 0);

		protected:
			FretboardEditScene* getScene() const;
	};

} // Fretboard

#endif // FRETBOARDAXIS_H

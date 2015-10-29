#ifndef FRETBOARDAXIS_H
#define FRETBOARDAXIS_H

#include <QGraphicsLineItem>

namespace Fretboard
{
	class FretboardAxis : public QGraphicsLineItem
	{
		public:
			FretboardAxis(const QLineF& line, QGraphicsItem* parent = 0);

		protected:
			virtual void focusInEvent(QFocusEvent* event) override;
			virtual void focusOutEvent(QFocusEvent* event) override;
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

		private:
			QColor m_defaultColor;
			QColor m_selectionColor;
	};

} // Fretboard

#endif // FRETBOARDAXIS_H

#ifndef FRETBOARDAXISEDITABLE_H
#define FRETBOARDAXISEDITABLE_H

#include "fretboardaxis.h"

namespace Fretboard
{
	class FretboardAxisEditable : public FretboardAxis
	{
		public:
			FretboardAxisEditable(QGraphicsItem* parent = 0);
			FretboardAxisEditable(const QLineF& line, QGraphicsItem* parent = 0);

		protected:
			virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
			virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
			virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

		private:
			QColor m_defaultColor;
			QColor m_selectionColor;
	};

} // Fretboard

#endif // FRETBOARDAXISEDITABLE_H

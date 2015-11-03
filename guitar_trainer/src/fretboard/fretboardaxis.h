#ifndef FRETBOARDAXIS_H
#define FRETBOARDAXIS_H

#include <QGraphicsLineItem>

namespace Fretboard
{
	class FretboardEditionScene;

	class FretboardAxis : public QGraphicsLineItem
	{
		public:
			FretboardAxis(const QLineF& line, QGraphicsItem* parent = 0);

		protected:
			virtual void focusInEvent(QFocusEvent* event) override;
			virtual void focusOutEvent(QFocusEvent* event) override;
			virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
			virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
			virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
			virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
			virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;

		private:
			FretboardEditionScene* getScene() const;

		private:
			QColor m_defaultColor;
			QColor m_selectionColor;
	};

} // Fretboard

#endif // FRETBOARDAXIS_H

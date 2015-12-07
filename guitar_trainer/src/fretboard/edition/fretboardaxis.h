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

#endif // FRETBOARDAXIS_H

#ifndef FRETBOARDAXISEDITOR_H
#define FRETBOARDAXISEDITOR_H

#include "fretboardaxis.h"

namespace Fretboard
{
	class FretboardAxisEditor : public FretboardAxis
	{
		public:
			FretboardAxisEditor(QGraphicsItem* parent = 0);
			FretboardAxisEditor(const QLineF& line, QGraphicsItem* parent = 0);

		protected:
			virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value) override;
	};

} // Fretboard

#endif // FRETBOARDAXISEDITOR_H

#ifndef FRETBOARDEDITIONVIEW_H
#define FRETBOARDEDITIONVIEW_H

#include "fretboardview.h"

namespace Fretboard
{
	class FretboardEditionView : public FretboardView
	{
		Q_OBJECT

		public:
			FretboardEditionView(QWidget* parent);
	};

} // Fretboard

#endif // FRETBOARDEDITIONVIEW_H

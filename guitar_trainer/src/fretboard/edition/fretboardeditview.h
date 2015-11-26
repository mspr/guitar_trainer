#ifndef FRETBOARDEDITVIEW_H
#define FRETBOARDEDITVIEW_H

#include "fretboard/fretboardview.h"

namespace Fretboard
{
	class FretboardEditView : public FretboardView
	{
		Q_OBJECT

		public:
			FretboardEditView(QWidget* parent);
	};

} // Fretboard

#endif // FRETBOARDEDITVIEW_H

#ifndef FRETBOARDEDITIONVIEW_H
#define FRETBOARDEDITIONVIEW_H

#include "fretboardview.h"

namespace Fretboard
{
	class FretboardEditionView : public FretboardView
	{
		public:
			FretboardEditionView(QWidget* parent);
			~FretboardEditionView();

			virtual void initScene(const QString& fileName) override;
			virtual void saveScene(const QString& fileName) override;

		protected:
			virtual void dragEnterEvent(QDragEnterEvent* event) override;
			virtual void dropEvent(QDropEvent* event) override;
	};

} // Fretboard

#endif // FRETBOARDEDITIONVIEW_H

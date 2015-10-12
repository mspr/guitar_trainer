#ifndef FRETBOARDEDITIONVIEW_H
#define FRETBOARDEDITIONVIEW_H

#include "fretboardview.h"

namespace Fretboard
{
	class FretboardEditionScene;

	class FretboardEditionView : public FretboardView
	{
		public:
			FretboardEditionView(QWidget* parent);

			virtual void initScene(const QString& fileName) override;
			virtual void saveScene(const QString& fileName) override;

		protected:
			virtual void dragEnterEvent(QDragEnterEvent* event) override;
			virtual void dragMoveEvent(QDragMoveEvent* event) override;
			virtual void dropEvent(QDropEvent* event) override;

		private:
			QScopedPointer<FretboardEditionScene> m_scene;
	};

} // Fretboard

#endif // FRETBOARDEDITIONVIEW_H

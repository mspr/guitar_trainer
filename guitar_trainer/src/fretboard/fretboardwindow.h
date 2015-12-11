#ifndef FRETBOARDWINDOW_H
#define FRETBOARDWINDOW_H

#include <QMainWindow>

namespace Fretboard
{
	class FretboardSceneBuilder;
	//class FretboardScene;

	class FretboardWindow : public QMainWindow
	{
		public:
			FretboardWindow(QWidget* parent = nullptr, Qt::WindowFlags flags = 0);
			virtual ~FretboardWindow();

		protected:
			virtual void dragEnterEvent(QDragEnterEvent* event) override;
			virtual void dropEvent(QDropEvent* event) override;

		protected slots:
			void open();

		protected:
			QScopedPointer<FretboardSceneBuilder> m_sceneBuilder;
			//QScopedPointer<FretboardScene> m_scene;
	};

} // Fretboard

#endif // FRETBOARDWINDOW_H

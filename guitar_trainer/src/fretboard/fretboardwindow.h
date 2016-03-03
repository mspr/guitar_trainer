#ifndef FRETBOARDWINDOW_H
#define FRETBOARDWINDOW_H

#include <QMainWindow>

namespace Fretboard
{
	class FretboardSceneBuilder;
	class FretboardScene;

	class FretboardWindow : public QMainWindow
	{
		Q_OBJECT

		public:
			FretboardWindow(QWidget* parent = nullptr, Qt::WindowFlags flags = 0);
			virtual ~FretboardWindow();

		protected:
			virtual void dragEnterEvent(QDragEnterEvent* event) override;
			virtual void dropEvent(QDropEvent* event) override;

			virtual void initScene_impl() = 0;

		protected slots:
			void open();

		private:
			bool tryCreateScene(const QString& fileName);
			void initScene();

		protected:
			QScopedPointer<FretboardSceneBuilder> m_sceneBuilder;
			QScopedPointer<FretboardScene> m_scene;
	};

} // Fretboard

#endif // FRETBOARDWINDOW_H

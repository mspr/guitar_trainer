#ifndef FRETBOARDEDITIONWINDOW_H
#define FRETBOARDEDITIONWINDOW_H

#include <QMainWindow>

namespace Ui { class FretboardEditionWindow; }

namespace Fretboard
{
	class FretboardEditionView;
	class FretboardEditionSceneLoader;
	class FretboardEditionScene;

	class FretboardEditionWindow : public QMainWindow
	{
		Q_OBJECT

		public:
			explicit FretboardEditionWindow(QWidget* parent = 0);
			~FretboardEditionWindow();

		protected:
			/*
			virtual void dragEnterEvent(QDragEnterEvent* event) override;
			virtual void dropEvent(QDropEvent* event) override;
			*/
			virtual void keyPressEvent(QKeyEvent* event) override;
			virtual void closeEvent(QCloseEvent* event) override;

		private:
			FretboardEditionView* editionView() const;
			bool tryCreateScene(const QString& fileName);

		private slots:
			void open();
			void onSceneCreation();
			void save();
			void switchToSelectionMode();
			void switchToEditionMode();

		private:
			Ui::FretboardEditionWindow* m_ui;
			QScopedPointer<FretboardEditionSceneLoader> m_sceneLoader;
			FretboardEditionScene* m_scene;
	};

} // Fretboard

#endif // FRETBOARDEDITIONWINDOW_H

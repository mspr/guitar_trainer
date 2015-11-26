#ifndef FRETBOARDEDITWINDOW_H
#define FRETBOARDEDITWINDOW_H

#include <QMainWindow>

namespace Ui { class FretboardEditWindow; }

namespace Fretboard
{
	class FretboardEditView;
	class FretboardEditScene;

	class FretboardEditWindow : public QMainWindow
	{
		Q_OBJECT

		public:
			explicit FretboardEditWindow(QWidget* parent = 0);
			~FretboardEditWindow();

		protected:
			virtual void dragEnterEvent(QDragEnterEvent* event) override;
			virtual void dropEvent(QDropEvent* event) override;
			virtual void keyPressEvent(QKeyEvent* event) override;
			virtual void closeEvent(QCloseEvent* event) override;

		private:
			FretboardEditView* editionView() const;
			bool tryCreateScene(const QString& fileName);

		private slots:
			void open();
			void initScene();
			void save();
			void switchToSelectionMode();
			void switchToEditionMode();

		private:
			Ui::FretboardEditWindow* m_ui;
			FretboardEditScene* m_scene;
	};

} // Fretboard

#endif // FRETBOARDEDITWINDOW_H

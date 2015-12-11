#ifndef FRETBOARDEDITWINDOW_H
#define FRETBOARDEDITWINDOW_H

#include "fretboard/fretboardwindow.h"

namespace Ui { class FretboardEditWindow; }

namespace Fretboard
{
	class FretboardEditView;
	class FretboardEditScene;

	class FretboardEditWindow : public FretboardWindow
	{
		Q_OBJECT

		public:
			explicit FretboardEditWindow(QWidget* parent = 0);
			~FretboardEditWindow();

		protected:
			virtual void keyPressEvent(QKeyEvent* event) override;
			virtual void closeEvent(QCloseEvent* event) override;

		private:
			FretboardEditView* editionView() const;
			bool tryCreateScene(const QString& fileName);

		private slots:
			void initScene();
			void save();
			void switchToSelectionMode();
			void switchToEditionMode();

		private:
			Ui::FretboardEditWindow* m_ui;
			QScopedPointer<FretboardEditScene> m_scene;
	};

} // Fretboard

#endif // FRETBOARDEDITWINDOW_H

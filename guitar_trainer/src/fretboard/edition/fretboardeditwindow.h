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

			virtual void initScene_impl() override;

			FretboardEditView* view() const;
			FretboardEditScene* scene() const;

		private slots:
			void save();
			void switchToSelectionMode();
			void switchToEditionMode();

		private:
			Ui::FretboardEditWindow* m_ui;
	};

} // Fretboard

#endif // FRETBOARDEDITWINDOW_H

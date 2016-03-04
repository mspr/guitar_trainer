#ifndef FRETBOARDPLAYWINDOW_H
#define FRETBOARDPLAYWINDOW_H

#include "fretboard/fretboardwindow.h"

namespace Ui			{ class FretboardPlayWindow; }
namespace Output	{ class OutputWindow; }

namespace Fretboard
{
	class FretboardPlayWindow : public FretboardWindow
	{
			Q_OBJECT

		public:
			explicit FretboardPlayWindow(QWidget* parent = 0);
			~FretboardPlayWindow();

		protected:
			virtual void resizeEvent(QResizeEvent* event) override;

			virtual void initScene_impl() override;

		private slots:
			void startEdition();
			void quitApplication();

		private:
			Ui::FretboardPlayWindow*	m_ui;
			Output::OutputWindow*			m_outputWindow;
	};

} // Fretboard

#endif // FRETBOARDPLAYWINDOW_H

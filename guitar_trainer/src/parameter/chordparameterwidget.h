#ifndef CHORDPARAMETERWIDGET_H
#define CHORDPARAMETERWIDGET_H

#include <QDockWidget>

namespace Ui { class ChordParameterWidget; }

namespace Parameter
{
	class ChordEditor;

	class ChordParameterWidget : public QDockWidget
	{
		Q_OBJECT

		public:
			explicit ChordParameterWidget(QWidget* parent = 0);
			~ChordParameterWidget();

		private slots:
			void openChordEditor();

		private:
			Ui::ChordParameterWidget* m_ui;
			QScopedPointer<ChordEditor> m_chordEditor;
	};

} // Parameter

#endif // CHORDPARAMETERWIDGET_H

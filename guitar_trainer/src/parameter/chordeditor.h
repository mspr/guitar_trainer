#ifndef CHORDEDITOR_H
#define CHORDEDITOR_H

#include <QWidget>

namespace Parameter
{
	class ChordEditor : public QWidget
	{
		Q_OBJECT

		public:
			explicit ChordEditor(QWidget* parent = 0);

		private:
			void setupUi();
	};

} // Parameter

#endif // CHORDEDITOR_H

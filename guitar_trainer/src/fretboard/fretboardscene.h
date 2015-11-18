#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace Fretboard
{
	class FretboardScene : public QGraphicsScene
	{
		public:
			FretboardScene(QObject* parent = 0);

		protected:
			virtual void init(const QPixmap& imagePix,
												const QHash<uint, double>& yByString,
												const QHash<uint, double>& xByFret);

		private:
			void initBackground(const QPixmap& imagePix);
			void initFretAndStringPositions(const QHash<uint, double>& xByFret,
																			const QHash<uint, double>& yByString);

		protected:
			QHash<uint, double> m_xByFret;
			QHash<uint, double> m_yByString;
	};

} // Fretboard

#endif // FRETBOARDSCENE_H

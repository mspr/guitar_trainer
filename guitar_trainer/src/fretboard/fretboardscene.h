#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

namespace Fretboard
{
	class FretboardNote;

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

			void addNote(const QPointF& pos);
			uint getNearestId(const QHash<uint, double>& posById, const double value) const;
			uint getNearestString(const QPointF& pos) const;
			uint getNearestFret(const QPointF& pos) const;

		protected:
			QHash<uint, double> m_xByFret;
			QHash<uint, double> m_yByString;
			QHash<QPoint, FretboardNote*> m_noteByFretboardPos;
	};

} // Fretboard

#endif // FRETBOARDSCENE_H

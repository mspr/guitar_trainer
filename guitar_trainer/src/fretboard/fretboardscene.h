#ifndef FRETBOARDSCENE_H
#define FRETBOARDSCENE_H

#include <QGraphicsScene>

#include "music/note.h"

namespace Fretboard
{
	class FretboardNote;

	class FretboardScene : public QGraphicsScene
	{
		public:
			FretboardScene(QObject* parent = 0);
			virtual ~FretboardScene();

		protected:
			virtual void init(const QPixmap& imagePix,
												const QList<Music::Note::ENote>& tuning,
												const QHash<uint, double>& yByString,
												const QHash<uint, double>& xByFret);

		private:
			void initBackground(const QPixmap& imagePix);
			void initTuning(const QList<Music::Note::ENote>& tuning);
			void initFretAndStringPositions(const QHash<uint, double>& xByFret,
																			const QHash<uint, double>& yByString);

			bool tryAddNote(const QPointF& pos);
			uint getNearestId(const QHash<uint, double>& posById, const double value) const;
			uint getNearestString(const QPointF& pos) const;
			uint getNearestFret(const QPointF& pos) const;
			Music::Note::ENote getNote(const QPair<uint, uint>& fretboardPos) const;

		protected:
			QList<Music::Note::ENote> m_tuning;
			QHash<uint, double> m_xByFret;
			QHash<uint, double> m_yByString;
			QHash<QPair<uint, uint>, FretboardNote*> m_noteByFretboardPos;
	};

} // Fretboard

#endif // FRETBOARDSCENE_H

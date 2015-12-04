#ifndef COMMANDADDAXISFRET_H
#define COMMANDADDAXISFRET_H

#include "commandaddaxis.h"

namespace Fretboard
{
	class FretboardAxisFret;

	class CommandAddAxisFret : public CommandAddAxis
	{
		public:
			CommandAddAxisFret(const QPointF& scenePos,
												 const QLineF& line,
												 FretboardEditScene* scene);

			virtual void redo() override;
			virtual void undo() override;

		private:
			FretboardAxisFret* m_fret;
	};

} // Fretboard

#endif // COMMANDADDAXISFRET_H

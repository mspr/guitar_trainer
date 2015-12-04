#ifndef COMMANDADDAXISSTRING_H
#define COMMANDADDAXISSTRING_H

#include "commandaddaxis.h"

namespace Fretboard
{
	class FretboardAxisString;

	class CommandAddAxisString : public CommandAddAxis
	{
		public:
			CommandAddAxisString(const QPointF& scenePos,
													 const QLineF& line,
													 FretboardEditScene* scene);

			virtual void redo() override;
			virtual void undo() override;

		private:
			FretboardAxisString* m_string;
	};

} // Fretboard

#endif // COMMANDADDAXISSTRING_H

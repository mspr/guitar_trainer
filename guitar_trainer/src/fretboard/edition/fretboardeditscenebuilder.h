#ifndef FRETBOARDEDITSCENEBUILDER_H
#define FRETBOARDEDITSCENEBUILDER_H

#include "fretboard/fretboardscenebuilder.h"
#include "fretboardeditscene.h"

namespace Fretboard
{
	class FretboardEditSceneBuilder : public FretboardSceneBuilder
	{
		public:
			FretboardEditSceneBuilder();

			virtual FretboardEditScene* tryCreateScene(const QString& fileName) override;
	};

} // Fretboard

#endif // FRETBOARDEDITSCENEBUILDER_H

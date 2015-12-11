#ifndef FRETBOARDPLAYSCENEBUILDER_H
#define FRETBOARDPLAYSCENEBUILDER_H

#include "fretboard/fretboardscenebuilder.h"
#include "fretboardplayscene.h"

namespace Fretboard
{
	class FretboardPlaySceneBuilder : public FretboardSceneBuilder
	{
		public:
			FretboardPlaySceneBuilder();

			virtual FretboardPlayScene* tryCreateScene(const QString& fileName) override;
	};

} // Fretboard

#endif // FRETBOARDPLAYSCENEBUILDER_H

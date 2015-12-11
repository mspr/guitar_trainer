#ifndef FRETBOARDSCENEBUILDER_H
#define FRETBOARDSCENEBUILDER_H

#include "fretboardscene.h"

namespace Fretboard
{
	class FretboardXmlReader;

	class FretboardSceneBuilder
	{
		public:
			FretboardSceneBuilder();
			virtual ~FretboardSceneBuilder();

			virtual FretboardScene* tryCreateScene(const QString& fileName) = 0;

		protected:
			bool load(const QString& fileName);

		protected:
			QScopedPointer<FretboardXmlReader> m_fretboardXmlReader;
			QPixmap m_pix;
	};

} // Fretboard

#endif // FRETBOARDSCENEBUILDER_H

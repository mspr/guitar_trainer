#ifndef FRETBOARDEDITIONSCENELOADER_H
#define FRETBOARDEDITIONSCENELOADER_H

#include <QString>

namespace Fretboard
{
	class FretboardEditionScene;

	class FretboardEditionSceneLoader
	{
		public:
			static FretboardEditionScene* tryCreateSceneFromOpenFile();
			static FretboardEditionScene* tryCreateSceneFromFile(const QString& fileName);

			static bool isSupported(const QString& fileName);
			static bool isImage(const QString& fileName);

		private:
			FretboardEditionSceneLoader();
	};

} // Fretboard

#endif // FRETBOARDEDITIONSCENELOADER_H

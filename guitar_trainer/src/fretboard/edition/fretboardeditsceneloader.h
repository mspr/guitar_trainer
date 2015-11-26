#ifndef FRETBOARDEDITSCENELOADER_H
#define FRETBOARDEDITSCENELOADER_H

#include <QString>

namespace Fretboard
{
	class FretboardEditScene;

	class FretboardEditSceneLoader
	{
		public:
			static FretboardEditScene* tryCreateSceneFromOpenFile();
			static FretboardEditScene* tryCreateSceneFromFile(const QString& fileName);

			static bool isSupported(const QString& fileName);
			static bool isImage(const QString& fileName);

		private:
			FretboardEditSceneLoader();
	};

} // Fretboard

#endif // FRETBOARDEDITSCENELOADER_H

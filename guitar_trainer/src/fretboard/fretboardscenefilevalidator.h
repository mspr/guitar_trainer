#ifndef FRETBOARDSCENEFILEVALIDATOR_H
#define FRETBOARDSCENEFILEVALIDATOR_H

#include <QString>

namespace Fretboard
{
	class FretboardSceneFileValidator
	{
		public:
			FretboardSceneFileValidator() = delete;

			static QString getOpenFileName();

			static bool isSupported(const QString& fileName);
			static bool isImage(const QString& fileName);
	};

} // Fretboard

#endif // FRETBOARDSCENEFILEVALIDATOR_H

#ifndef FRETBOARDEDITIONSCENELOADER_H
#define FRETBOARDEDITIONSCENELOADER_H

#include <QObject>

namespace Fretboard
{
	class FretboardEditionWindow;
	class FretboardEditionScene;

	class FretboardEditionSceneLoader : public QObject
	{
		public:
			FretboardEditionSceneLoader(FretboardEditionWindow& fretboardEditionWindow);
			FretboardEditionScene* tryCreateSceneFromOpenFile();
			FretboardEditionScene* tryCreateSceneFromFile(const QString& fileName);

		protected:
			virtual bool eventFilter(QObject* object, QEvent* event) override;

	private:
			bool isSupported(const QString& fileName);
			bool isImage(const QString& fileName);
	};

} // Fretboard

#endif // FRETBOARDEDITIONSCENELOADER_H

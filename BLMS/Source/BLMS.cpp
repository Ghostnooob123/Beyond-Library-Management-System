#include <iostream>

#include "LibraryEngine.h"

int WinMain()
{

    LibraryEngine* library = new LibraryEngine();

	while (library->isAppRunning())
	{
		library->update();

		library->render();
	}
	delete library;

	return EXIT_SUCCESS;
}

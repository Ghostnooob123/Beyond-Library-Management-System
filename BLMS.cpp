#include <iostream>

#include "LibraryEngine.h"

int main()
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

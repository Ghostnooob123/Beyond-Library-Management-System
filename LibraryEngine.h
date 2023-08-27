#ifndef LIBRARY_ENGINE_H
#define LIBRARY_ENGINE_H

#include <unordered_map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

class LibraryEngine
{
public:
	//Constructor & Destructor
	LibraryEngine();
	~LibraryEngine();
public:
	//Accessors
	const bool isAppRunning() const;

	//Public Engine functions
	void update();
	void render();
private:
	//Private Engine functions
	void pollEvents();
	void updateMousePos();

	//Open library button Update & Render methods
	void updateBLMS_ButtonOpenLibrary();
	void renderBLMS_ButtonOpenLibrary(sf::RenderTarget* target);

	//Add book button Update & Render methods
	void updateBLMS_ButtonAddBook();
	void renderBLMS_ButtonAddBook(sf::RenderTarget* target);

	//Exit button Update & Render methods
	void updateBLMS_ButtonExit();
	void renderBLMS_ButtonExit(sf::RenderTarget* target);

	//Books panel Update & Render methods
	void updateBLMS_BooksPanel();
	void renderBLMS_BooksPanel(sf::RenderTarget* target);
private:
	//Variables
	  //Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	  //Events
	sf::Event eventAction;
	  //Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	  //Buttons
	sf::ConvexShape openLibraryButton;
	sf::ConvexShape addBookButton;
	sf::ConvexShape exitButton;

	  //List of books Panel
	sf::RectangleShape booksPanel;

	//App engine logic
	bool isLibraryOpen;

	float centerX; //Center of the screen by X
	float centerY; //Center of the screen by Y

	//Private functions
	void initVariables();
	void initWindow();
	void initBLMS_ButtonOpenLibrary();
	void initBLMS_ButtonAddBook();
	void initBLMS_ButtonExit();
	void initBLMS_BooksPanel();
};
#endif // !LIBRARY_ENGINE_H
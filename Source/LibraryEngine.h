#ifndef LIBRARY_ENGINE_H
#define LIBRARY_ENGINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "LibraryGUI.h"

class LibraryEngine final
{
public:
	//Constructor & Destructor
	LibraryEngine();
	~LibraryEngine();
	//Accessors
	const bool isAppRunning() const;

	//Public Engine functions
	void update();
	void render();
private:
	//Private Engine functions
	void pollEvents();
	void updateMousePos();
	void libraryTest();
	void uniqueBook_CheckMark();
	void orderFrom_A_To_Z();
	void orderFrom_Z_To_A();
	void removeBook();
	void updateLibrary();
	//Variables
	  //Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	  //Events
	sf::Event eventAction;
	  //Mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	  //Texture
	sf::Texture texture;
	sf::Sprite sprite;

	//App engine logic
	std::vector<sf::Text> newBookInput_Storage; //Every "new" book have unique ID & name.
	std::vector<sf::Text> books_Storage; //Every book have unique ID & name.
	std::vector<sf::RectangleShape> checkBoxes;
	sf::RectangleShape checkBox;
	std::vector<sf::RectangleShape> deleteRequests;
	sf::RectangleShape deleteRequest;
	std::vector<sf::Text> removeBookInput_Storage; //remove book from the list storage for the text

	bool updateOnStart;
	std::string userInputString;
	std::string removeInputString;
	sf::Text userInputText;
	float moveDown;
	size_t maxChars;
	size_t maxCharsLine;
	bool shiftPressed;
	size_t newLine;
	char forbiddenSymbol;

	float scrollPosition;
	float scrollIncrement;

	LibraryGUI* libraryGUI = new LibraryGUI;

	float centerX; //Center of the screen by X
	float centerY; //Center of the screen by Y

	//Private functions
	void initVariables();
	void initWindow();
	void initBLMS_LOGO();
};
#endif // !LIBRARY_ENGINE_H
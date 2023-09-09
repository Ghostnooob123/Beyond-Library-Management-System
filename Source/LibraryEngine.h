#ifndef LIBRARY_ENGINE_H
#define LIBRARY_ENGINE_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <set>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "LibraryGUI.h"

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

	void updateLibrary();
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
	  //Texture
	sf::Texture texture;
	sf::Sprite sprite;

	//App engine logic
	std::unordered_map<unsigned, sf::Text> newBookInput_Storage; //Every book have unique ID & name.
	std::unordered_map<unsigned, sf::Text> books_Storage; //Every book have unique ID & name.
	std::vector<sf::RectangleShape> checkBoxes;
	sf::RectangleShape checkBox;

	int ID;
	bool updateOnStart;
	std::string userInputString;
	sf::Text userInputText;

	int maxCharsOnLine;
	int	charsOnLine;

	LibraryGUI* libraryGUI = new LibraryGUI;

	float centerX; //Center of the screen by X
	float centerY; //Center of the screen by Y

	//Private functions
	void initVariables();
	void initWindow();
	void initBLMS_LOGO();
};
#endif // !LIBRARY_ENGINE_H
#ifndef LIBRARY_GUI_H
#define LIBRARY_GUI_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class LibraryGUI
{
public:
	//Constructor & Destructor
	LibraryGUI();
	~LibraryGUI();
public:
	//Accessors
	const void setWindow(sf::RenderWindow* window);
	const bool requestExit() const;
	const bool requestOpenLibrary() const;
	const void changeRequestOpenLibrary();
	const bool requestAddBook() const;
	const void changeRequestAddBook();
	const sf::Text userInput() const;
	const sf::Text printBook() const;

	//Public GUI functions
	   //Open library button Update & Render methods
	void updateBLMS_ButtonOpenLibrary(sf::Vector2f& mousePosView, float& centerX, float& centerY);
	void renderBLMS_ButtonOpenLibrary(sf::RenderTarget* target);

	   //Add book button Update & Render methods
	void updateBLMS_ButtonAddBook(sf::Vector2f& mousePosView, float& centerX, float& centerY);
	void renderBLMS_ButtonAddBook(sf::RenderTarget* target, std::unordered_map<unsigned, sf::Text>& newBookInput_Storage);

	   //Exit button Update & Render methods
	void updateBLMS_ButtonExit(sf::Vector2f& mousePosView, float& centerX, float& centerY);
	void renderBLMS_ButtonExit(sf::RenderTarget* target);

	   //Books panel Update & Render methods
	void updateBLMS_BooksPanel();
	void renderBLMS_BooksPanel(sf::RenderTarget* target, std::unordered_map<unsigned, sf::Text>& books_Storage, sf::Vector2f& mousePosView, std::vector<sf::RectangleShape>& checkBoxes, sf::RectangleShape& checkBox);

	void updateBLMS_CheckboxPanel(sf::Vector2f& mousePosView);
	void renderBLMS_CheckboxPanel(sf::RenderTarget* target);

	void pollEvent();
private:
	//Private GUI functions
	void updateViewPanel();
private:
	//Variables
	//Window
	sf::RenderWindow* target;
	//Event 
	sf::Event actionEvent;
	  //Buttons
	sf::ConvexShape openLibraryButton;
	sf::ConvexShape addBookButton;
	sf::ConvexShape exitButton;
	     //Buttons UI's 
	sf::Font mainFont; //Main button font for the application
	sf::Text UI_OpenLibraryButton;
	sf::Text UI_AddBookButton;
	sf::Text UI_exitButton;
	     //Buttons highlighters
	sf::ConvexShape highLighter_ButtonOpenLibrary;
	sf::ConvexShape highLighter_ButtonAddBook;
	sf::ConvexShape highLighter_ButtonExit;
	  //List of books Panel
	sf::RectangleShape booksPanel;
	sf::View booksView;
	sf::RectangleShape line;
	sf::RectangleShape yourListPanel;
	sf::Text UI_yourListPanel;
	sf::Text printBookText;
	  //Add book panel
	sf::Font booksFont;
	sf::ConvexShape addBookBar;
	sf::Text userInputText;
	//Checkbox panel
	sf::RectangleShape checkboxPanel;
	std::vector<sf::RectangleShape> checks;

	  //App engine logic
	bool isLibraryOpen;
	bool requestToClose;
	bool addBook;
	float scrollPosition;
	unsigned int book;
	sf::Color colorChanger;
	bool colorPicked;
	bool isColorPicker;
	unsigned selectedBook;
	bool mouseClicked;

	//Private functions
	void initVariables();
	void initBLMS_Font();
	void initBLMS_ButtonOpenLibrary();
	void initBLMS_ButtonAddBook();
	void initBLMS_ButtonExit();

	void initBLMS_BooksPanel();
	void initBLMS_BooksView();
	void initBLMS_YourListPanel();
	void initBLMS_newLine();
	void initBLMS_addNewBookBar();
	void initBLMS_userInputText();
	void initBLMS_printBookText();
	void initBLMS_CheckboxPanel();
};
#endif // !LIBRARY_GUI_H
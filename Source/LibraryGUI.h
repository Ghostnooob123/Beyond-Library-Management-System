#ifndef LIBRARY_GUI_H
#define LIBRARY_GUI_H

#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class LibraryGUI final
{
public:
	//Constructor & Destructor
	LibraryGUI();
	~LibraryGUI();

	//Accessors
	const void setWindow(sf::RenderWindow* window);
	const bool requestExit() const;
	const bool requestOpenLibrary() const;
	const void changeRequestOpenLibrary();
	const bool requestAddBook() const;
	const void changeRequestAddBook();
	const bool requestInfoPanel() const;
	const bool requestDeleteBook() const;
	const std::string getBookToDelete() const;
	const void changeDeleteBookRequest();
	const bool getPanelBounds(sf::Vector2f& mousePosView) const;

	const void clearRemoveBookBar(std::string& removeInputString, std::vector<sf::Text>& removeBookInput_Storage);
	const void clearAddBookBar(std::string& userInputString, std::vector<sf::Text>& newBookInput_Storage);

	const void limitReached();
	const void limitReverse();

	const bool requestShowFilters() const;
	const bool requestCheckBoxColor() const;
	const bool requestOrder_A_To_Z() const;
	const bool requestOrder_Z_To_A() const;

	const sf::Text userInput() const;
	const sf::Text printBook() const;

	//Public GUI functions
	//Buttons
	   //Open library button Update & Render methods
	void updateBLMS_ButtonOpenLibrary(sf::Vector2f& mousePosView, float& centerX, float& centerY, size_t& typeSymbol);
	void renderBLMS_ButtonOpenLibrary(sf::RenderTarget* target);

	   //Add book button Update & Render methods
	void updateBLMS_ButtonAddBook(sf::Vector2f& mousePosView, float& centerX, float& centerY, size_t& typeSymbol);
	void renderBLMS_ButtonAddBook(sf::RenderTarget* target, std::vector<sf::Text>& newBookInput_Storage);

	   //Exit button Update & Render methods
	void updateBLMS_ButtonExit(sf::Vector2f& mousePosView, float& centerX, float& centerY);
	void renderBLMS_ButtonExit(sf::RenderTarget* target);

	   //Filter button Update & Render methods
	void updateBLMS_ButtonFilter(sf::Vector2f& mousePosView, float& centerX, float& centerY, size_t& typeSymbol);
	void renderBLMS_ButtonFilter(sf::RenderTarget* target);

	   //Close library button Update & Render methods
	void updateBLMS_ButtonCloseLibrary(sf::Vector2f& mousePosView, float& centerX, float& centerY, size_t& typeSymbol);
	void renderBLMS_ButtonCloseLibrary(sf::RenderTarget* target);

	   //Info button Update & Render methods
	void updateBLMS_ButtonInfo(sf::Vector2f& mousePosView, float& centerX, float& centerY, size_t& typeSymbol);
	void renderBLMS_ButtonInfo(sf::RenderTarget* target);

	//Panels
	void updateBLMS_InfoPanel(sf::Vector2f& mousePosView);
	void renderBLMS_InfoPanel(sf::RenderTarget* target);

	  //Filter Panel Update & Render methods
	void updateBLMS_Filters(sf::Vector2f& mousePosView);
	void renderBLMS_Filters(sf::RenderTarget* target);

	void updateBLMS_CheckboxPanel(sf::Vector2f& mousePosView);
	void renderBLMS_CheckboxPanel(sf::RenderTarget* target);

	   //Books panel Update & Render methods
	void updateBLMS_BooksPanel();
	void renderBLMS_BooksPanel(
		sf::RenderTarget* target,
		std::vector<sf::Text>& books_Storage, 
		sf::Vector2f& mousePosView, 
		std::vector<sf::RectangleShape>& checkBoxes,
		sf::RectangleShape& checkBox, 
		std::vector<sf::RectangleShape>& deleteRequests, 
		sf::RectangleShape& deleteReqest,
		float scrollPosition,
	    float scrollIncrement,
		size_t& typeSymbol
	);

	void updateBLMS_RemoveBook(sf::Vector2f& mousePosView, float& centerX, float& centerY, size_t& typeSymbol);
	void renderBLMS_RemoveBook(sf::RenderTarget* target, std::vector<sf::Text>& removeBookInput_Storage);

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
	sf::ConvexShape filterButton;
	sf::ConvexShape closeLibraryButton;
	sf::ConvexShape infoButton;
	     //Buttons UI's 
	sf::Font mainFont; //Main button font for the application
	sf::Text UI_OpenLibraryButton;
	sf::Text UI_AddBookButton;
	sf::Text UI_ExitButton;
	sf::Text UI_FilterButton;
	sf::Text UI_CloseLibraryButton;
	sf::Text UI_InfoButton;
	     //Buttons highlighters
	sf::ConvexShape highLighter_ButtonOpenLibrary;
	sf::ConvexShape highLighter_ButtonAddBook;
	sf::ConvexShape highLighter_ButtonExit;
	sf::ConvexShape highLighter_ButtonFilter;
	sf::ConvexShape highLighter_ButtonCloseLibrary;
	sf::ConvexShape highLighter_ButtonInfo;
	  //List of books Panel
	sf::RectangleShape booksPanel;
	sf::View booksView;
	sf::RectangleShape line;
	std::vector<sf::Text> deleteBookUIs;
	sf::Text deleteBookButton;
	sf::RectangleShape yourListPanel;
	sf::Text UI_yourListPanel;
	sf::Text printBookText;
	  //Add book panel
	sf::Font booksFont;
	sf::RectangleShape addBookBar;
	sf::Text userInputText;
	sf::RectangleShape enterBookPanel;
	sf::Text enterBook;
	sf::CircleShape closeAddBookBar;
	sf::Text limitWarn;
	bool closeAddBook;
	  //Info panel
	sf::RectangleShape InfoPanel;
	sf::Text UI_InfoPanel;
	sf::CircleShape closeInfoPanel;
	  //Remove book 
	bool isBookDelete;
	std::string bookToDelete;
	sf::Text removeBookText;
	sf::RectangleShape removBookBar;
	sf::RectangleShape warningPanel;
	sf::Text UI_warningPanel;
	sf::CircleShape closeRemoveBookBar;
	bool closeRemoveBook;
	//Filter options
	sf::RectangleShape filterPanel;
	bool showFilters;
	sf::CircleShape closeFilterPanel;
		//Checkbox panel
	sf::RectangleShape checkFilter;
	sf::Text UI_checkFilter;
	sf::RectangleShape checkboxPanel;
	std::vector<sf::RectangleShape> checks;
	sf::CircleShape closeCheckboxPanel;
	bool colorPicked;
	bool isColorPicker;
	bool errorColor;
	   //A-Z filter
	sf::RectangleShape orderA_Z_Filter;
	sf::Text UI_orderA_Z_Filter;
	bool isOrderA_Z;
	   //Z-A filter
	sf::RectangleShape orderZ_A_Filter;
	sf::Text UI_orderZ_A_Filter;
	bool isOrderZ_A;
	   //Remove filter
	sf::RectangleShape removeFilter;
	sf::Text UI_removeFilter;
	bool isRemoveFilter;
	//Warning
	sf::RectangleShape existingBookWarn;
	sf::Text UI_existingBookWarn;
	sf::CircleShape closeExistingBookWarn;
	bool getWarn;

	  //App engine logic
	bool isLibraryOpen;
	bool requestToClose;
	bool addBook;
	float moveDown;
	size_t book;
	sf::Color colorChanger;
	bool showHowToUse;
	float increaseBar;

	//Private functions
	void initVariables();
	void initBLMS_Font();
	void initBLMS_ButtonOpenLibrary();
	void initBLMS_ButtonAddBook();
	void initBLMS_ButtonExit();
	void initBLMS_ButtonFilter();
	void initBLMS_ButtonCloseLibrary();
	void initBLMS_ButtonInfoHowToUse();

	void initBLMS_BooksPanel();
	void initBLMS_InfoPanel();
	void initBLMS_BooksView();
	void initBLMS_YourListPanel();
	void initBLMS_newLine();
	void initBLMS_DeleteBook();
	void initBLMS_addNewBookBar();
	void initBLMS_userInputText();
	void initBLMS_printBookText();
	void initBLMS_removeBookBar();
	void initBLMS_removeBookText();
	void initBLMS_tempLimitWarn();

	void initBLMS_Filters();
	void initBLMS_FilterPanel();
	void initBLMS_CheckMarks();
	void initBLMS_A_Z_Filter();
	void initBLMS_Z_A_Filter();
	void initBLMS_CheckboxPanel();
};
#endif // !LIBRARY_GUI_H
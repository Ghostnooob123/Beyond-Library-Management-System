#include "LibraryGUI.h"

//Constructor & Destructor
LibraryGUI::LibraryGUI()
{
	/*
	   @Constructor
	   - Initialize member variables and UI elements.
	*/

	this->initVariables();
	this->initBLMS_Font();
	this->initBLMS_ButtonOpenLibrary();
	this->initBLMS_ButtonAddBook();
	this->initBLMS_ButtonExit();
	this->initBLMS_ButtonFilter();
	this->initBLMS_ButtonCloseLibrary();
	this->initBLMS_ButtonInfoHowToUse();

	this->initBLMS_BooksPanel();
	this->initBLMS_InfoPanel();
	this->initBLMS_BooksView();
	this->initBLMS_YourListPanel();
	this->initBLMS_newLine();
	this->initBLMS_DeleteBook();
	this->initBLMS_addNewBookBar();
	this->initBLMS_userInputText();
	this->initBLMS_printBookText();
	this->initBLMS_removeBookBar();
	this->initBLMS_removeBookText();

	this->initBLMS_Filters();
	this->initBLMS_CheckboxPanel();
}
LibraryGUI::~LibraryGUI()
{
	//Destructor implementation if needed
}

//Accessors
const void LibraryGUI::setWindow(sf::RenderWindow* window)
{
	this->target = window;
}
const bool LibraryGUI::requestExit() const
{
	/*
	  @return const bool
	  - Check if there is any request to close the app.
	*/
	return this->requestToClose;
}
const bool LibraryGUI::requestOpenLibrary() const
{
	/*
	  @return const bool
	  - Check if there is any request to open the library.
	*/
	return this->isLibraryOpen;
}
const void LibraryGUI::changeRequestOpenLibrary()
{
	this->isLibraryOpen = false;
}
const bool LibraryGUI::requestAddBook() const
{
	return this->addBook;
}
const void LibraryGUI::changeRequestAddBook()
{
	this->addBook = false;
}
const bool LibraryGUI::requestInfoPanel() const
{
	return this->showHowToUse;
}
const bool LibraryGUI::requestDeleteBook() const
{
	return this->isBookDelete;
}
const std::string LibraryGUI::getBookToDelete() const
{
	return this->bookToDelete;
}
const void LibraryGUI::changeDeleteBookRequest() 
{
	this->isBookDelete = false;
}

const bool LibraryGUI::requestShowFilters() const
{
	return this->showFilters;
}
const bool LibraryGUI::requestCheckBoxColor() const
{
	return this->isColorPicker;
}
const bool LibraryGUI::requestOrder_A_To_Z() const
{
	return this->isOrderA_Z;
}
const bool LibraryGUI::requestOrder_Z_To_A() const
{
	return this->isOrderZ_A;
}

const sf::Text LibraryGUI::userInput() const
{
	return this->userInputText;
}
const sf::Text LibraryGUI::printBook() const
{
	return this->printBookText;
}

//Public GUI functions
   //Open Library Update & Render methods
void LibraryGUI::updateBLMS_ButtonOpenLibrary(sf::Vector2f& mousePosView, float& centerX, float& centerY)
{
	/*
	  @return void
	  - Update Open library button.
	  - Set positions depending on mouse event.
	  - Set button's highlighter.
	  - This button handles opening the library list.
	*/

	float highlighterWidth = 10.0f;
	float highlighterHeight = 65.0f;

	//Open list & update highlighter
	if (this->openLibraryButton.getGlobalBounds().contains(mousePosView))
	{
		this->openLibraryButton.setPosition(sf::Vector2f(centerX - 1125.0f, centerY - 550.0f));

		highlighterWidth = 30.0f;
		highlighterHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonOpenLibrary.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonOpenLibrary.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonOpenLibrary.setOutlineThickness(2.0f);
		this->highLighter_ButtonOpenLibrary.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonOpenLibrary.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonOpenLibrary.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonOpenLibrary.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonOpenLibrary.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonOpenLibrary.setPosition(sf::Vector2f(centerX - 960.0f, centerY - 550.0f));
	}
	else
	{
		this->openLibraryButton.setPosition(sf::Vector2f(centerX - 1130.0f, centerY - 550.0f));

		//Highlither UI by default
		this->highLighter_ButtonOpenLibrary.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonOpenLibrary.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonOpenLibrary.setOutlineThickness(2.0f);
		this->highLighter_ButtonOpenLibrary.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonOpenLibrary.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonOpenLibrary.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonOpenLibrary.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonOpenLibrary.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonOpenLibrary.setPosition(sf::Vector2f(centerX - 980.0f, centerY - 550.0f));
	}

	if (this->openLibraryButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isLibraryOpen = true;
	}

	if (this->isLibraryOpen)
	{
		updateBLMS_BooksPanel();
	}
}
void LibraryGUI::renderBLMS_ButtonOpenLibrary(sf::RenderTarget* target)
{
	/*
	  @return void
	  - Display Open library button :
	  Display Open library button UI, highlighter.
	*/

	if (!this->isLibraryOpen)
	{
		target->draw(this->openLibraryButton);
		target->draw(this->UI_OpenLibraryButton);
		target->draw(this->highLighter_ButtonOpenLibrary);
	}
}

   //Add book Update & Render methods
void LibraryGUI::updateBLMS_ButtonAddBook(sf::Vector2f& mousePosView, float& centerX, float& centerY)
{
	/*
	  @return void
	  - Update Add book button.
	  - Set positions depending on mouse event.
	  - Set button's highlighter.
	  - Update new book bar.
	*/

	float highlighterWidth = 10.0f;
	float highlighterHeight = 65.0f;

	//Adding new book & updating highlighters
	if (this->addBookButton.getGlobalBounds().contains(mousePosView))
	{
		this->addBookButton.setPosition(sf::Vector2f(centerX - 1125.0f, centerY - 450.0f));

		highlighterWidth = 30.0f;
		highlighterHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonAddBook.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonAddBook.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonAddBook.setOutlineThickness(2.0f);
		this->highLighter_ButtonAddBook.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonAddBook.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonAddBook.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonAddBook.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonAddBook.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonAddBook.setPosition(sf::Vector2f(centerX - 985.0f, centerY - 450.0f));
	}
	else
	{
		this->addBookButton.setPosition(sf::Vector2f(centerX - 1150.0f, centerY - 450.0f));

		//Highlither UI by default
		this->highLighter_ButtonAddBook.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonAddBook.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonAddBook.setOutlineThickness(2.0f);
		this->highLighter_ButtonAddBook.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonAddBook.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonAddBook.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonAddBook.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonAddBook.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonAddBook.setPosition(sf::Vector2f(centerX - 1000.0f, centerY - 450.0f));
	}

	if (this->addBookButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->addBook = true;
		this->showFilters = false;
		this->isBookDelete = false;
	}

	if (this->addBook)
	{
		this->addBookBar.setPosition(sf::Vector2f(centerX - 735.0f, centerY - 310.0f));
		this->enterBookPanel.setPosition(sf::Vector2f(centerX - 735.0f, centerY - 348.0f));
	}
}
void LibraryGUI::renderBLMS_ButtonAddBook(sf::RenderTarget* target, std::vector<sf::Text>& newBookInput_Storage)
{
	/*
	  @return void
	  - Display Add button :
	  Display Add button UI, highlighter.
	  - Display add new book bar.
	*/
	target->draw(this->addBookButton);
	target->draw(this->UI_AddBookButton);
	target->draw(this->highLighter_ButtonAddBook);

	if (this->addBook)
	{
		target->draw(this->addBookBar);
		target->draw(this->enterBookPanel);
		target->draw(this->enterBook);
		for (auto& newBook : newBookInput_Storage)
		{
			newBook.setPosition(sf::Vector2f(this->addBookBar.getPosition().x + 5.0f, this->addBookBar.getPosition().y + 15.0f));
			target->draw(newBook);
		}
	}
}

   //Exit button Update & Render methods
void LibraryGUI::updateBLMS_ButtonExit(sf::Vector2f& mousePosView, float& centerX, float& centerY)
{
	/*
	  @return void
	  - Update Exit button.
	  - Set positions depending on mouse event.
	  - Set button's highlighter.
	  - This button close and clear the program.
	*/

	float highlighterWidth = 10.0f;
	float highlighterHeight = 65.0f;

	//Shutdown the program & update highlighters
	if (this->exitButton.getGlobalBounds().contains(mousePosView))
	{
		this->exitButton.setPosition(sf::Vector2f(centerX - 1180.0f, centerY + 50.0f));

		highlighterWidth = 30.0f;
		highlighterHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonExit.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonExit.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonExit.setOutlineThickness(2.0f);
		this->highLighter_ButtonExit.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonExit.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonExit.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonExit.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonExit.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonExit.setPosition(sf::Vector2f(centerX - 1030.0f, centerY + 50.0f));
	}
	else
	{
		this->exitButton.setPosition(sf::Vector2f(centerX - 1200.0f, centerY + 50.0f));

		//Highlither UI by default
		this->highLighter_ButtonExit.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonExit.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonExit.setOutlineThickness(2.0f);
		this->highLighter_ButtonExit.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonExit.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonExit.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonExit.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonExit.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonExit.setPosition(sf::Vector2f(centerX - 1050.0f, centerY + 50.0f));
	}

	if (this->exitButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		requestToClose = true;
	}
}
void LibraryGUI::renderBLMS_ButtonExit(sf::RenderTarget* target)
{
	/*
	  @return void
	  - Display Exit button :
	  Display Exit button UI, highlighter.
	*/
	target->draw(this->exitButton);
	target->draw(this->UI_ExitButton);
	target->draw(this->highLighter_ButtonExit);
}

   //Filter button Update & Render methods
void LibraryGUI::updateBLMS_ButtonFilter(sf::Vector2f& mousePosView, float& centerX, float& centerY)
{
	/*
		  @return void
		  - Update Filter button.
		  - Set positions depending on mouse event.
		  - Set button's highlighter.
		  - This button shows library filters.
	*/

	float highlighterWidth = 10.0f;
	float highlighterHeight = 65.0f;

	if (this->filterButton.getGlobalBounds().contains(mousePosView))
	{
		this->filterButton.setPosition(sf::Vector2f(centerX - 843.0f, centerY - 30.0f));

		highlighterWidth = 25.0f;
		highlighterHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonFilter.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonFilter.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonFilter.setOutlineThickness(2.0f);
		this->highLighter_ButtonFilter.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonFilter.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonFilter.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonFilter.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonFilter.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonFilter.setPosition(sf::Vector2f(centerX - 945.0f, centerY - 30.0f));
	}
	else
	{
		this->filterButton.setPosition(sf::Vector2f(centerX - 843.0f, centerY - 30.0f));

		//Highlither UI by default
		this->highLighter_ButtonFilter.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonFilter.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonFilter.setOutlineThickness(2.0f);
		this->highLighter_ButtonFilter.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonFilter.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonFilter.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonFilter.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonFilter.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonFilter.setPosition(sf::Vector2f(centerX - 940.0f, centerY - 30.0f));
	}

	if (this->filterButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->showFilters = true;
		this->addBook = false;
		this->showHowToUse = false;
		this->isBookDelete = false;
	}
}
void LibraryGUI::renderBLMS_ButtonFilter(sf::RenderTarget* target)
{
	/*
	  @return void
	  - Display Filter button :
	  Display Filter button UI, highlighter.
	*/

	target->draw(this->filterButton);
	target->draw(this->UI_FilterButton);
	target->draw(this->highLighter_ButtonFilter);
}

   //Close library button Update & Render methods
void LibraryGUI::updateBLMS_ButtonCloseLibrary(sf::Vector2f& mousePosView, float& centerX, float& centerY)
{
	/*
		  @return void
		  - Update Close library button.
		  - Set positions depending on mouse event.
		  - Set button's highlighter.
		  - This button handles closing the library list.
	*/

	float highlighterWidth = 10.0f;
	float highlighterHeight = 65.0f;

	//Close list & update highlighter
	if (this->closeLibraryButton.getGlobalBounds().contains(mousePosView))
	{
		this->closeLibraryButton.setPosition(sf::Vector2f(centerX - 1125.0f, centerY - 370.0f));

		highlighterWidth = 30.0f;
		highlighterHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonCloseLibrary.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonCloseLibrary.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonCloseLibrary.setOutlineThickness(2.0f);
		this->highLighter_ButtonCloseLibrary.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonCloseLibrary.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonCloseLibrary.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonCloseLibrary.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonCloseLibrary.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonCloseLibrary.setPosition(sf::Vector2f(centerX - 960.0f, centerY - 370.0f));
	}
	else
	{
		this->closeLibraryButton.setPosition(sf::Vector2f(centerX - 1130.0f, centerY - 370.0f));

		//Highlither UI by default
		this->highLighter_ButtonCloseLibrary.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonCloseLibrary.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonCloseLibrary.setOutlineThickness(2.0f);
		this->highLighter_ButtonCloseLibrary.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonCloseLibrary.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonCloseLibrary.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonCloseLibrary.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonCloseLibrary.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonCloseLibrary.setPosition(sf::Vector2f(centerX - 980.0f, centerY - 370.0f));
	}

	if (this->closeLibraryButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isLibraryOpen = false;
		this->showFilters = false;
		this->showHowToUse = false;
		this->isBookDelete = false;
	}
}
void LibraryGUI::renderBLMS_ButtonCloseLibrary(sf::RenderTarget* target)
{
	/*
	  @return void
	  - Display Close library button :
	  Display Close library button UI, highlighter.
	*/
	target->draw(this->closeLibraryButton);
	target->draw(this->UI_CloseLibraryButton);
	target->draw(this->highLighter_ButtonCloseLibrary);
}

   //Info button Update & Render methods
void LibraryGUI::updateBLMS_ButtonInfo(sf::Vector2f& mousePosView, float& centerX, float& centerY)
{
	/*
		  @return void
		  - Update Info button.
		  - Set positions depending on mouse event.
		  - Set button's highlighter.
		  - This button shows library info and how to use guide.
	*/

	float highlighterWidth = 10.0f;
	float highlighterHeight = 55.0f;

	//Show info how to use & update highlighters
	if (this->infoButton.getGlobalBounds().contains(mousePosView))
	{
		this->infoButton.setPosition(sf::Vector2f(centerX - 825.0f, centerY + 45.0f));

		highlighterWidth = 25.0f;
		highlighterHeight = 55.0f;
		//Highlither UI by default
		this->highLighter_ButtonInfo.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonInfo.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonInfo.setOutlineThickness(2.0f);
		this->highLighter_ButtonInfo.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonInfo.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonInfo.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonInfo.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonInfo.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonInfo.setPosition(sf::Vector2f(centerX - 916.0f, centerY + 45.0f));
	}
	else
	{
		this->infoButton.setPosition(sf::Vector2f(centerX - 828.0f, centerY + 45.0f));

		//Highlither UI by default
		this->highLighter_ButtonInfo.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonInfo.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonInfo.setOutlineThickness(2.0f);
		this->highLighter_ButtonInfo.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonInfo.setPoint(0, sf::Vector2f(400 - highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-left
		this->highLighter_ButtonInfo.setPoint(1, sf::Vector2f(400 + highlighterWidth / 2, 300 - highlighterHeight / 2)); // Top-right
		this->highLighter_ButtonInfo.setPoint(2, sf::Vector2f(450 + highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-right
		this->highLighter_ButtonInfo.setPoint(3, sf::Vector2f(450 - highlighterWidth / 2, 300 + highlighterHeight / 2)); // Bottom-left
		this->highLighter_ButtonInfo.setPosition(sf::Vector2f(centerX - 908.0f, centerY + 45.0f));
	}

	if (this->infoButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->showHowToUse = true;
		this->isLibraryOpen = false;
		this->showFilters = false;
		this->isBookDelete = false;
		this->addBook = false;
	}
}
void LibraryGUI::renderBLMS_ButtonInfo(sf::RenderTarget* target)
{
	/*
	  @return void
	  - Display Info button :
	  Display Info button UI, highlighter.
	*/
	target->draw(this->infoButton);
	target->draw(this->UI_InfoButton);
	target->draw(this->highLighter_ButtonInfo);
}

   //Books panel Update & Render methods
void LibraryGUI::updateBLMS_BooksPanel()
{
	/*
	  @return void

	*/
}
void LibraryGUI::renderBLMS_BooksPanel(
	sf::RenderTarget* target, 
	std::vector<sf::Text>& books_Storage, 
	sf::Vector2f& mousePosView, 
	std::vector<sf::RectangleShape>& checkBoxes, 
	sf::RectangleShape& checkBox, 
	std::vector<sf::RectangleShape>& deleteRequests, 
	sf::RectangleShape& deleteRequest )
{
	/*
	  @return void
	  - Display Books panel.
	  - Display books panel view.
	  - Polling events.
	  - Display books storage elements.
	*/

	target->draw(this->booksPanel);

	target->draw(this->yourListPanel);
	target->draw(this->UI_yourListPanel);

	for (this->book = 0; this->book < books_Storage.size(); ++this->book)
	{
		if (this->book >= 28)
		{
			this->pollEvent();
		}

		checkBox.setOutlineThickness(2.5f);
		checkBox.setSize(sf::Vector2f(40.0f, 40.0f));

		checkBoxes.push_back(checkBox);

		deleteRequest.setOutlineColor(sf::Color::Black);
		deleteRequest.setOutlineThickness(2.0f);
		deleteRequest.setSize(sf::Vector2f(100.0f, 40.0f));

		deleteRequests.push_back(deleteRequest);

		//Adjust the book's position using the scrollPosition
		books_Storage[this->book].setPosition(sf::Vector2f(
			this->booksPanel.getPosition().x + 100.0f, 
			this->booksPanel.getPosition().y + 18.0f + this->moveDown - this->scrollPosition
		));

		//Adjust the book's marks position using the scrollPosition
		checkBoxes[this->book].setPosition(sf::Vector2f(
			this->booksPanel.getPosition().x + 10.0f,
			this->booksPanel.getPosition().y + 19.0f + this->moveDown - this->scrollPosition
		));

		//Adjust the books's delete option position using the scrollPosition
		deleteRequests[this->book].setPosition(sf::Vector2f(
			this->booksPanel.getPosition().x + 930.0f,
			this->booksPanel.getPosition().y + 18.0f + this->moveDown - this->scrollPosition
		));

		std::ifstream inputFile("BOOKS_STORAGE_CHECK.txt");
		if (!inputFile)
		{
			std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
			return; // Exit early if unable to open the output file.
		}

		std::string str;
		while (std::getline(inputFile, str)) {
			std::istringstream r(str);
			std::string name;
			char sp;
			std::string color;
			r >> color >> sp;
			std::getline(r, name);
			name.erase(0, 1);

			sf::Text tempText;
			tempText.setString(name);

			if (books_Storage[this->book].getString() == tempText.getString())
			{
				if (color == "green")
				{
					checkBoxes[this->book].setFillColor(sf::Color(76, 194, 8));
				}
				else if (color == "yellow")
				{
					checkBoxes[this->book].setFillColor(sf::Color(242, 236, 48));
				}
				else if (color == "red")
				{
					checkBoxes[this->book].setFillColor(sf::Color(212, 56, 44));
				}
				else
				{
					checkBoxes[this->book].setFillColor(sf::Color::White);
				}
			}
		}
		inputFile.close();

		if (!books_Storage[this->book].getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			books_Storage[this->book].setFillColor(sf::Color::Black);
			target->draw(books_Storage[this->book]);
		}
		if (!checkBoxes[this->book].getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			if (checkBoxes[this->book].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if(this->isColorPicker){
					if (this->colorChanger != sf::Color::White)
					{
						checkBoxes[this->book].setFillColor(this->colorChanger);

						std::ifstream inputFileColor("BOOKS_STORAGE_CHECK.txt");
						if (!inputFileColor)
						{
							std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
							return; // Exit early if unable to open the input file.
						}

						std::string name;
						name = books_Storage[this->book].getString();
						std::string color;
						if (this->colorChanger == sf::Color(76, 194, 8))
						{
							color = "green";
							this->errorColor = false;
						}
						else if (this->colorChanger == sf::Color(242, 236, 48))
						{
							color = "yellow";
							this->errorColor = false;
						}
						else if (this->colorChanger == sf::Color(212, 56, 44))
						{
							color = "red";
							this->errorColor = false;
						}
						else
						{
							this->errorColor = true;
							inputFileColor.close();
						}

						std::vector<std::string> updatedLines; // Store updated lines in memory.

						std::string str;

						while (std::getline(inputFileColor, str)) {
							std::istringstream r(str);

							char sp;
							std::string c;
							std::string oldName;
							r >> c >> sp;

							std::getline(r, oldName);
							oldName.erase(0, 1);

							if (oldName != name)
							{
								// If the old book name doesn't match the current book name, keep the old line.
								updatedLines.push_back(str);
							}
						}

						inputFileColor.close();

						// Reopen the output file to write the updated data.
						std::ofstream outputFile("BOOKS_STORAGE_CHECK.txt");
						if (!outputFile)
						{
							std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
							return; // Exit early if unable to open the output file.
						}

						// Write back the updated lines and the new book.
						for (const std::string& line : updatedLines)
						{
							outputFile << line << '\n';
						}

						if (!this->errorColor)
						{
							// Add the new book with the updated color.
							outputFile << color << " - " << name << '\n';
						}

						outputFile.close();
					}
				}
			}
			checkBoxes[this->book].setOutlineColor(sf::Color::Black);
			target->draw(checkBoxes[this->book]);
		}

		if (!deleteRequests[this->book].getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			if (deleteRequests[this->book].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->isBookDelete = true;
				this->bookToDelete = books_Storage[this->book].getString();
			}
			deleteRequests[this->book].setFillColor(sf::Color(235, 241, 245));
			target->draw(deleteRequests[this->book]);
		}

		this->deleteBookButton.setPosition(sf::Vector2f(this->booksPanel.getPosition().x + 930.0f, this->booksPanel.getPosition().y + 20.0f + this->moveDown + 1.0f - this->scrollPosition));

		if (!this->deleteBookButton.getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			this->deleteBookButton.setFillColor(sf::Color::Black);
			target->draw(this->deleteBookButton);
		}

		this->moveDown += 55.0f;

		if (!this->line.getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			this->line.setFillColor(sf::Color::Black);
			target->draw(this->line);
		}
		//Adjust the line's position
		this->line.setPosition(sf::Vector2f(this->booksPanel.getPosition().x, this->booksPanel.getPosition().y + 9.0f + this->moveDown + 1.0f - this->scrollPosition));
	}
	this->moveDown = 0.0f;
}
// Having issues with the scroll events for scrolling down and up with the mouse ^^^.


void LibraryGUI::updateBLMS_RemoveBook(float& centerX, float& centerY)
{
	if (this->isBookDelete)
	{
		this->addBook = false;
		this->removBookBar.setPosition(sf::Vector2f(centerX - 735.0f, centerY - 310.0f));
		this->warningPanel.setPosition(sf::Vector2f(centerX - 725.0f, centerY - 388.0f));
	}
}
void LibraryGUI::renderBLMS_RemoveBook(sf::RenderTarget* target, std::vector<sf::Text>& removeBookInput_Storage)
{
	if (this->isBookDelete)
	{
		target->draw(this->removBookBar);
		target->draw(this->warningPanel);
		target->draw(this->UI_warningPanel);
		target->draw(this->closeWarningPanel);
		for (auto& removeBook : removeBookInput_Storage)
		{
			removeBook.setPosition(sf::Vector2f(this->removBookBar.getPosition().x + 5.0f, this->removBookBar.getPosition().y + 15.0f));
			target->draw(removeBook);
		}
	}
}

//Panels
void LibraryGUI::updateBLMS_InfoPanel(sf::Vector2f& mousePosView)
{
	if (this->closeInfoPanel.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->showHowToUse = false;
	}
}
void LibraryGUI::renderBLMS_InfoPanel(sf::RenderTarget* target)
{
	target->draw(this->InfoPanel);
	target->draw(this->closeInfoPanel);
	target->draw(this->UI_InfoPanel);
}
 //Filters
void LibraryGUI::updateBLMS_Filters(sf::Vector2f& mousePosView)
{
	if (this->checkFilter.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isColorPicker = true;
	}
	if (this->orderA_Z_Filter.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isOrderA_Z = true;
		this->isOrderZ_A = false;
	}
	if (this->orderZ_A_Filter.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isOrderZ_A = true;
		this->isOrderA_Z = false;
	}
	if (this->closeFilterPanel.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->showFilters = false;
	}
}
void LibraryGUI::renderBLMS_Filters(sf::RenderTarget* target)
{
	target->draw(this->filterPanel);
	target->draw(this->closeFilterPanel);

	target->draw(this->checkFilter);
	target->draw(this->UI_checkFilter);

	target->draw(this->orderA_Z_Filter);
	target->draw(this->UI_orderA_Z_Filter);

	target->draw(this->orderZ_A_Filter);
	target->draw(this->UI_orderZ_A_Filter);
}

void LibraryGUI::updateBLMS_CheckboxPanel(sf::Vector2f& mousePosView)
{
	for (size_t i = 0; i < this->checks.size(); ++i)
	{
		if (checks[i].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->colorChanger = checks[i].getFillColor();

			checks[i].setOutlineThickness(4.0f);
		}
		else
		{
			checks[i].setOutlineThickness(2.5f);
		}
	}

	if (this->closeCheckboxPanel.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isColorPicker = false;
		this->colorChanger = sf::Color::White;
	}
}
void LibraryGUI::renderBLMS_CheckboxPanel(sf::RenderTarget* target)
{
	target->draw(checkboxPanel);

	for (auto& check : checks)
	{
		target->draw(check);
	}

	target->draw(this->closeCheckboxPanel);
}

void LibraryGUI::pollEvent()
{
	/*
	  @return void
	  - Check real-time events.
	*/

	while (this->target->pollEvent(this->actionEvent))
	{
		switch (this->actionEvent.type)
		{
		case sf::Event::MouseWheelScrolled:
			if (this->actionEvent.mouseWheelScroll.delta > 0)
			{
				if (scrollPosition > 0)
				{
					this->scrollPosition -= this->scrollIncrement;
				}
			}
			if (this->actionEvent.mouseWheelScroll.delta < 0)
			{
				this->scrollPosition += this->scrollIncrement;
			}
			break;
		}
	}
}

//Private GUI functions
//void updateViewPanel();

//void LibraryGUI::updateViewPanel()
//{
//	/*
//	  @return void
//	  - Update the view's position to stay within bounds.
//	  - Update the books view by scrolling down or up.
//	*/
//
//	// Calculate the top and bottom bounds of your content
//	float contentTop = this->booksPanel.getPosition().y;
//	float contentBottom = this->booksPanel.getPosition().y + this->booksPanel.getSize().y;
//
//	// Calculate the top and bottom bounds of the view
//	float viewTop = this->booksView.getCenter().y - this->booksView.getSize().y / 2;
//	float viewBottom = this->booksView.getCenter().y + this->booksView.getSize().y / 2;
//
//	// Update the view's position to stay within the bounds of your content
//	if (viewTop < contentTop) {
//		// Adjust the view's center to keep it within the top bounds
//		this->booksView.setCenter(this->booksView.getCenter().x, this->booksView.getSize().y / 2);
//	}
//	else if (viewBottom > contentBottom) {
//		// Adjust the view's center to keep it within the bottom bounds
//		this->booksView.setCenter(this->booksView.getCenter().x, contentBottom - this->booksView.getSize().y / 2);
//	}
//}

//

//Private functions
void LibraryGUI::initVariables()
{
	/*
	  @return void
	  - Initialize member variables.
	*/

	this->isLibraryOpen = false;
	this->requestToClose = false;
	this->addBook = false; 
	this->moveDown =  0.0f;
	this->scrollPosition = 0.0f;
	this->scrollIncrement = 15.0f;
	this->book = 0;
	this->colorChanger = sf::Color::White;
	this->showFilters = false;
	this->errorColor = false;
	this->isOrderA_Z = false;
	this->showHowToUse = false;
	this->isBookDelete = false;

	this->isColorPicker = false;
}
void LibraryGUI::initBLMS_Font()
{
	/*
	  @return void
	  - Load the main font for the GUI.
	*/
	if (!this->mainFont.loadFromFile("Source/Fonts/OpenSans-Bold.ttf"))
	{
		std::cerr << "[ERROR] can't open font from [Source/Fonts/OpenSans-Bold.ttf]\n";
	}
	if (!this->booksFont.loadFromFile("Source/Fonts/OpenSans-Bold.ttf"))
	{
		std::cerr << "[ERROR] can't open font from [Source/Fonts/OpenSans-Bold.ttf]\n";
	}
}
void LibraryGUI::initBLMS_ButtonOpenLibrary()
{
	/*
	  @return void
	  - Initialize the Open Library button and its UI text.
	*/

	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//Open library button by default
	this->openLibraryButton.setFillColor(sf::Color(235, 241, 245));
	this->openLibraryButton.setOutlineColor(sf::Color::Black);
	this->openLibraryButton.setOutlineThickness(2.0f);
	this->openLibraryButton.setPointCount(4);
	//Open library button width & height by default
	this->openLibraryButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->openLibraryButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->openLibraryButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->openLibraryButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
	//Open library button UI
	this->UI_OpenLibraryButton.setFont(this->mainFont);
	this->UI_OpenLibraryButton.setFillColor(sf::Color::Black);
	this->UI_OpenLibraryButton.setCharacterSize(20);
	this->UI_OpenLibraryButton.setString(" Open Your List ");
	this->UI_OpenLibraryButton.setPosition(this->openLibraryButton.getPosition().x + 10.0f, this->openLibraryButton.getPosition().y + 185.0f);
}
void LibraryGUI::initBLMS_ButtonAddBook()
{
	/*
	  @return void
	  - Initialize the Add Book button and its UI text.
	*/

	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//Add Book button by default
	this->addBookButton.setFillColor(sf::Color(235, 241, 245));
	this->addBookButton.setOutlineColor(sf::Color::Black);
	this->addBookButton.setOutlineThickness(2.0f);
	this->addBookButton.setPointCount(4);
	//Add Book button width & height by default
	this->addBookButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->addBookButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->addBookButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->addBookButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
	//Add book button UI
	this->UI_AddBookButton.setFont(this->mainFont);
	this->UI_AddBookButton.setFillColor(sf::Color::Black);
	this->UI_AddBookButton.setCharacterSize(20);
	this->UI_AddBookButton.setString(" New Book ");
	this->UI_AddBookButton.setPosition(this->addBookButton.getPosition().x + 15.0f, this->addBookButton.getPosition().y + 285.0f);
}
void LibraryGUI::initBLMS_ButtonExit()
{
	/*
	  @return void
	  - Initialize the Exit button and its UI text.
	*/

	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//Exit button by default
	this->exitButton.setFillColor(sf::Color(235, 241, 245));
	this->exitButton.setOutlineColor(sf::Color::Black);
	this->exitButton.setOutlineThickness(2.0f);
	this->exitButton.setPointCount(4);
	//Exit button width & height by default
	this->exitButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->exitButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->exitButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->exitButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
	//Exit button UI
	this->UI_ExitButton.setFont(this->mainFont);
	this->UI_ExitButton.setFillColor(sf::Color::Black);
	this->UI_ExitButton.setCharacterSize(50);
	this->UI_ExitButton.setString("Exit");
	this->UI_ExitButton.setPosition(this->exitButton.getPosition().x + 10.0f, this->exitButton.getPosition().y + 770.0f);
}
void LibraryGUI::initBLMS_ButtonFilter()
{
	/*
	  @return void
	  - Initialize the Filter button and its UI text.
	*/

	float buttonWidth = 180.0f;
	float buttonHeight = 65.0f;

	//Filter button by default
	this->filterButton.setFillColor(sf::Color(235, 241, 245));
	this->filterButton.setOutlineColor(sf::Color::Black);
	this->filterButton.setOutlineThickness(2.0f);
	this->filterButton.setPointCount(4);
	//Filter button width & height by default
	this->filterButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->filterButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->filterButton.setPoint(2, sf::Vector2f(400 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->filterButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
	//Filter button UI
	this->UI_FilterButton.setFont(this->mainFont);
	this->UI_FilterButton.setFillColor(sf::Color::Black);
	this->UI_FilterButton.setCharacterSize(40);
	this->UI_FilterButton.setString("Filters");
	this->UI_FilterButton.setPosition(this->filterButton.getPosition().x + 260.0f, this->filterButton.getPosition().y + 693.0f);
}
void LibraryGUI::initBLMS_ButtonCloseLibrary()
{
	/*
	  @return void
	  - Initialize the Open Library button and its UI text.
	*/

	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//Open library button by default
	this->closeLibraryButton.setFillColor(sf::Color(235, 241, 245));
	this->closeLibraryButton.setOutlineColor(sf::Color::Black);
	this->closeLibraryButton.setOutlineThickness(2.0f);
	this->closeLibraryButton.setPointCount(4);
	//Open library button width & height by default
	this->closeLibraryButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->closeLibraryButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->closeLibraryButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->closeLibraryButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
	//Open library button UI
	this->UI_CloseLibraryButton.setFont(this->mainFont);
	this->UI_CloseLibraryButton.setFillColor(sf::Color::Black);
	this->UI_CloseLibraryButton.setCharacterSize(20);
	this->UI_CloseLibraryButton.setString(" Close Your List ");
	this->UI_CloseLibraryButton.setPosition(this->closeLibraryButton.getPosition().x + 10.0f, this->closeLibraryButton.getPosition().y + 365.0f);
}
void LibraryGUI::initBLMS_ButtonInfoHowToUse()
{
	/*
	  @return void
	  - Initialize the Open Library button and its UI text.
	*/

	float buttonWidth = 160.0f;
	float buttonHeight = 55.0f;

	//Open library button by default
	this->infoButton.setFillColor(sf::Color(235, 241, 245));
	this->infoButton.setOutlineColor(sf::Color::Black);
	this->infoButton.setOutlineThickness(2.0f);
	this->infoButton.setPointCount(4);
	//Open library button width & height by default
	this->infoButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->infoButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->infoButton.setPoint(2, sf::Vector2f(400 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->infoButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
	//Open library button UI
	this->UI_InfoButton.setFont(this->mainFont);
	this->UI_InfoButton.setFillColor(sf::Color::Black);
	this->UI_InfoButton.setCharacterSize(20);
	this->UI_InfoButton.setString("How To Use");
	this->UI_InfoButton.setPosition(this->infoButton.getPosition().x + 280.0f, this->infoButton.getPosition().y + 780.0f);
}

void LibraryGUI::initBLMS_BooksPanel()
{
	/*
	  @return void
	  - Initialize the books panel.
	*/

	//Books Panel by deafult
	this->booksPanel.setFillColor(sf::Color(235, 241, 245));
	this->booksPanel.setSize(sf::Vector2f(1050.0f, 15550.0f)); //Set a large height
	this->booksPanel.setOutlineColor(sf::Color::Black);
	this->booksPanel.setOutlineThickness(3.0f);
	this->booksPanel.setPosition(sf::Vector2f(400.0f, 0.0f));

}
void LibraryGUI::initBLMS_InfoPanel()
{
	/*
	  @return void
	  - Initialize the Info panel and its UI's text.
	*/

	//Info panel by deafult
	this->InfoPanel.setSize(sf::Vector2f(800.0f, 500.0f));
	this->InfoPanel.setPosition(sf::Vector2f(this->booksPanel.getPosition().x, this->booksPanel.getPosition().y + 130.0f));
	this->InfoPanel.setFillColor(sf::Color(235, 241, 245));
	this->InfoPanel.setOutlineColor(sf::Color::Black);
	this->InfoPanel.setOutlineThickness(2.0f);

	//Info Panel Close by deafult
	this->closeInfoPanel.setPosition(sf::Vector2f(this->InfoPanel.getPosition().x + 790.0f, this->InfoPanel.getPosition().y - 5.0f));
	this->closeInfoPanel.setRadius(8.0f);
	this->closeInfoPanel.setFillColor(sf::Color(66, 66, 64));
	this->closeInfoPanel.setOutlineColor(sf::Color::Black);
	this->closeInfoPanel.setOutlineThickness(2.0f);

	//Info Panel UI by deafult
	this->UI_InfoPanel.setFont(this->mainFont);
	this->UI_InfoPanel.setFillColor(sf::Color::Black);
	this->UI_InfoPanel.setCharacterSize(17);
	std::string Info;
	Info = "* The purpose of this program is to make it easier to save your own books in one big collection, \n where you can filter them : Sort, Mark, Remove.\n\n - \"Open Your List\", this button opens your list of books. \n - \"New Book\", this button allows you to add new book to your list. \n - \"Filters\", this button allows you to filter your list of books. \n - \"Exit\", this button closes the program and saves your data. \n - \"Close Your List\", this button closes the list of books you have.\n - \"Remove\", this button allows you to remove ( Delete ) book from the list.\n   (* Keep in mind you will see a warning when removing a book. *) \n\n -If there is any issues, bugs, errors reports or just want to suggest improvements\n feel free to send feedback: \n Email: ivorahnev15@gmail.com \n Discord: Ghostnooob123\n";

	this->UI_InfoPanel.setString(Info);
	this->UI_InfoPanel.setPosition(sf::Vector2f(this->InfoPanel.getPosition().x + 4.0f, this->InfoPanel.getPosition().y + 25.0f));

}
void LibraryGUI::initBLMS_BooksView()
{
	/*
	  @return void
	  - Initialize the Books view.
	*/

	//booksView by deafult
	this->booksView.setSize(sf::Vector2f(2150.0f, 1050.0f)); //Set the size of the visible view
	float viewCenterX = booksPanel.getPosition().x - 200.0f + booksPanel.getSize().x / 2;
	float viewCenterY = booksPanel.getPosition().y + booksPanel.getPosition().y / 2;
	this->booksView.setCenter(sf::Vector2f(viewCenterX, viewCenterY));
	this->scrollPosition = 0.0f; //Initialize scroll position
}
void LibraryGUI::initBLMS_YourListPanel()
{
	/*
	  @return void
	  - Initialize the your list panel and its UI text.
	*/

	//yourListPanel panel by default
	this->yourListPanel.setFillColor(sf::Color::White);
	this->yourListPanel.setSize(sf::Vector2f(1050.0f, 60.0f));
	this->yourListPanel.setOutlineColor(sf::Color::Black);
	this->yourListPanel.setOutlineThickness(3.0f);
	this->yourListPanel.setPosition(sf::Vector2f(this->booksPanel.getPosition().x, this->booksPanel.getPosition().y + 3.0f));

	//yourListPanel panel UI
	this->UI_yourListPanel.setFont(this->mainFont);
	this->UI_yourListPanel.setFillColor(sf::Color::Black);
	this->UI_yourListPanel.setCharacterSize(40);
	this->UI_yourListPanel.setString(" Your list ");
	this->UI_yourListPanel.setPosition(this->yourListPanel.getPosition().x + 450.0f, this->yourListPanel.getPosition().y + 5.0f);
}
void LibraryGUI::initBLMS_newLine()
{
	/*
	  @return void
	  - Initialize the new line UI.
	*/

	//New line after each book by default
	this->line.setSize(sf::Vector2f(1050.0f, 2.0f));
	this->line.setFillColor(sf::Color::Black);
}
void LibraryGUI::initBLMS_DeleteBook()
{
	/*
	  @return void
	  - Initialize the Remove book UI.
	*/

	//Delete book UI
	this->deleteBookButton.setFont(this->mainFont);
	this->deleteBookButton.setFillColor(sf::Color::Black);
	this->deleteBookButton.setCharacterSize(25);
	this->deleteBookButton.setString("Remove");
}
void LibraryGUI::initBLMS_addNewBookBar()
{
	/*
	  @return void
	  - Initialize the add new book bar.
	  - Initialize the Enter book panel.
	*/

	float addBarWidth = 350.0f;
	float addBarHeight = 60.0f;

	//Enter book panel by default
	this->enterBookPanel.setFillColor(sf::Color(252, 252, 250));
	this->enterBookPanel.setOutlineColor(sf::Color::Black);
	this->enterBookPanel.setOutlineThickness(2.5f);
	this->enterBookPanel.setSize(sf::Vector2f(addBarWidth - 210.0f, addBarHeight - 30.0f));

	this->enterBook.setFont(this->mainFont); // Set the font you want to use
	this->enterBook.setCharacterSize(20); // Set the font size
	this->enterBook.setFillColor(sf::Color::Black); // Set the text color
	this->enterBook.setString("Enter a book");
	this->enterBook.setPosition(sf::Vector2f(this->enterBookPanel.getPosition().x + 20.0f, this->enterBookPanel.getPosition().y + 105.0f));

	//addNewBookBar by default
	this->addBookBar.setFillColor(sf::Color(252, 252, 250));
	this->addBookBar.setOutlineColor(sf::Color::Black);
	this->addBookBar.setOutlineThickness(2.5f);
	this->addBookBar.setSize(sf::Vector2f(addBarWidth, addBarHeight));
}
void LibraryGUI::initBLMS_userInputText()
{
	/*
	  @return void
	  - Initialize the user input text.
	*/

	//userInputText by default
	this->userInputText.setFont(this->booksFont); // Set the font you want to use
	this->userInputText.setCharacterSize(20); // Set the font size
	this->userInputText.setFillColor(sf::Color::Black); // Set the text color
	this->userInputText.setString("NONE");
	this->userInputText.setPosition(sf::Vector2f(this->addBookBar.getPosition().x, this->addBookBar.getPosition().y + 10000.0f));
}
void LibraryGUI::initBLMS_printBookText()
{
	/*
	  @return void
	  - Initialize the print book text.
	*/

	//printBookText by default
	this->printBookText.setFont(this->booksFont); // Set the font you want to use
	this->printBookText.setCharacterSize(35); // Set the font size
	this->printBookText.setFillColor(sf::Color::Black); // Set the text color
	this->printBookText.setString("NONE");
	this->printBookText.setPosition(sf::Vector2f(this->addBookBar.getPosition().x, this->addBookBar.getPosition().y + 10000.0f));
}
void LibraryGUI::initBLMS_removeBookBar()
{
	/*
	  @return void
	  - Initialize the add new book bar.
	*/

	float addBarWidth = 350.0f;
	float addBarHeight = 60.0f;


	//Warning panel by default
	this->warningPanel.setFillColor(sf::Color(252, 252, 250));
	this->warningPanel.setOutlineColor(sf::Color::Black);
	this->warningPanel.setOutlineThickness(2.5f);
	this->warningPanel.setSize(sf::Vector2f(addBarWidth - 20.0f, addBarHeight - 10.0f));

	this->UI_warningPanel.setFont(this->mainFont); // Set the font you want to use
	this->UI_warningPanel.setCharacterSize(18); // Set the font size
	this->UI_warningPanel.setFillColor(sf::Color::Black); // Set the text color
	this->UI_warningPanel.setString("                       * Warning *\n    Type the book name to remove it.");
	this->UI_warningPanel.setPosition(sf::Vector2f(this->warningPanel.getPosition().x + 20.0f, this->warningPanel.getPosition().y + 64.0f));

	//Warning Panel Close by deafult
	this->closeWarningPanel.setPosition(sf::Vector2f(this->warningPanel.getPosition().x + 790.0f, this->warningPanel.getPosition().y - 5.0f));
	this->closeWarningPanel.setRadius(8.0f);
	this->closeWarningPanel.setFillColor(sf::Color(66, 66, 64));
	this->closeWarningPanel.setOutlineColor(sf::Color::Black);
	this->closeWarningPanel.setOutlineThickness(2.0f);


	//Remove book bar by default
	this->removBookBar.setFillColor(sf::Color(252, 252, 250));
	this->removBookBar.setOutlineColor(sf::Color::Black);
	this->removBookBar.setOutlineThickness(2.5f);
	this->removBookBar.setSize(sf::Vector2f(addBarWidth, addBarHeight));
}
void LibraryGUI::initBLMS_removeBookText()
{
	/*
		  @return void
		  - Initialize the print book text.
	*/

		//printBookText by default
	this->removeBookText.setFont(this->booksFont); // Set the font you want to use
	this->removeBookText.setCharacterSize(35); // Set the font size
	this->removeBookText.setFillColor(sf::Color::Black); // Set the text color
	this->removeBookText.setString("NONE");
	this->removeBookText.setPosition(sf::Vector2f(this->addBookBar.getPosition().x, this->addBookBar.getPosition().y + 10000.0f));
}

void LibraryGUI::initBLMS_Filters()
{
	/*
	  @return void
	  - Initialize the Filters.
	*/

	this->initBLMS_FilterPanel();
	this->initBLMS_CheckMarks();
	this->initBLMS_A_Z_Filter();
	this->initBLMS_Z_A_Filter();
}
void LibraryGUI::initBLMS_FilterPanel()
{
	/*
	  @return void
	  - Initialize the Filter Panel.
	*/

	//Filter Panel by default
	this->filterPanel.setSize(sf::Vector2f(300.0f, 230.0f));
	this->filterPanel.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 350.0f, this->booksPanel.getPosition().y + 430.0f));
	this->filterPanel.setOutlineColor(sf::Color::Black);
	this->filterPanel.setOutlineThickness(2.0f);
	this->filterPanel.setFillColor(sf::Color(235, 241, 245));

	//Filter Panel Close by default
	this->closeFilterPanel.setPosition(sf::Vector2f(this->filterPanel.getPosition().x + 290.0f, this->filterPanel.getPosition().y - 5.0f));
	this->closeFilterPanel.setRadius(8.0f);
	this->closeFilterPanel.setFillColor(sf::Color(66, 66, 64));
	this->closeFilterPanel.setOutlineColor(sf::Color::Black);
	this->closeFilterPanel.setOutlineThickness(2.0f);
}
void LibraryGUI::initBLMS_CheckMarks()
{
	/*
	  @return void
	  - Initialize the Filter to mark books.
	*/

	//Check mark by default
	this->checkFilter.setFillColor(sf::Color(192, 194, 192));
	this->checkFilter.setOutlineColor(sf::Color::Black);
	this->checkFilter.setOutlineThickness(1.0f);
	this->checkFilter.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 330.0f, this->booksPanel.getPosition().y + 445.0f));
	this->checkFilter.setSize(sf::Vector2f(100.0f, 30.0f));

	//Check mark Filter button UI by default
	this->UI_checkFilter.setFont(this->mainFont);
	this->UI_checkFilter.setFillColor(sf::Color::Black);
	this->UI_checkFilter.setCharacterSize(15);
	this->UI_checkFilter.setString("check marks");
	this->UI_checkFilter.setPosition(this->checkFilter.getPosition().x + 2.0f, this->checkFilter.getPosition().y + 5.0f);
}
void LibraryGUI::initBLMS_A_Z_Filter()
{
	/*
	  @return void
	  - Initialize the Filter from A to Z.
	*/

	//Filter from A to Z by default
	this->orderA_Z_Filter.setFillColor(sf::Color(192, 194, 192));
	this->orderA_Z_Filter.setOutlineColor(sf::Color::Black);
	this->orderA_Z_Filter.setOutlineThickness(1.0f);
	this->orderA_Z_Filter.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 170.0f, this->booksPanel.getPosition().y + 445.0f));
	this->orderA_Z_Filter.setSize(sf::Vector2f(100.0f, 30.0f));

	//Filter from A to Z UI by default
	this->UI_orderA_Z_Filter.setFont(this->mainFont);
	this->UI_orderA_Z_Filter.setFillColor(sf::Color::Black);
	this->UI_orderA_Z_Filter.setCharacterSize(15);
	this->UI_orderA_Z_Filter.setString("Filter: A -> Z");
	this->UI_orderA_Z_Filter.setPosition(this->orderA_Z_Filter.getPosition().x + 5.0f, this->orderA_Z_Filter.getPosition().y + 5.0f);
}
void LibraryGUI::initBLMS_Z_A_Filter()
{
	/*
	  @return void
	  - Initialize the Filter from Z to A.
	*/

	//Filter from Z to A by default
	this->orderZ_A_Filter.setFillColor(sf::Color(192, 194, 192));
	this->orderZ_A_Filter.setOutlineColor(sf::Color::Black);
	this->orderZ_A_Filter.setOutlineThickness(1.0f);
	this->orderZ_A_Filter.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 170.0f, this->booksPanel.getPosition().y + 500.0f));
	this->orderZ_A_Filter.setSize(sf::Vector2f(100.0f, 30.0f));

	//Filter from Z to A UI by default
	this->UI_orderZ_A_Filter.setFont(this->mainFont);
	this->UI_orderZ_A_Filter.setFillColor(sf::Color::Black);
	this->UI_orderZ_A_Filter.setCharacterSize(15);
	this->UI_orderZ_A_Filter.setString("Filter: Z -> A");
	this->UI_orderZ_A_Filter.setPosition(this->orderZ_A_Filter.getPosition().x + 5.0f, this->orderZ_A_Filter.getPosition().y + 5.0f);
}
void LibraryGUI::initBLMS_CheckboxPanel()
{
	/*
	  @return void
	  - Initialize the Check Box Panel.
	*/

	//Check box Panel by default
	this->checkboxPanel.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 310.0f, this->booksPanel.getPosition().y + 30.0f));
	this->checkboxPanel.setSize(sf::Vector2f(230.0f, 100.0f));
	this->checkboxPanel.setFillColor(sf::Color(235, 241, 245));
	this->checkboxPanel.setOutlineColor(sf::Color::Black);
	this->checkboxPanel.setOutlineThickness(2.5f);

	float moveRight{ 0.0f };

	//Check marks by default
	for (int i = 0; i < 3; ++i)
	{
		sf::RectangleShape check;
		if (i == 0)
		{
			check.setFillColor(sf::Color(76, 194, 8));
		}
		if (i == 1)
		{
			check.setFillColor(sf::Color(242, 236, 48));
		}
		if (i == 2)
		{
			check.setFillColor(sf::Color(212, 56, 44));
		}
		check.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 295.0f + moveRight, this->booksPanel.getPosition().y + 60.0f));
		moveRight += 80.0f;
		check.setOutlineColor(sf::Color::Black);
		check.setSize(sf::Vector2f(40.0f, 40.0f));
		this->checks.push_back(check);
	}

	//Check mark Panel close by default
	this->closeCheckboxPanel.setPosition(sf::Vector2f(this->checkboxPanel.getPosition().x + 220.0f, this->checkboxPanel.getPosition().y - 5.0f));
	this->closeCheckboxPanel.setRadius(8.0f);
	this->closeCheckboxPanel.setFillColor(sf::Color(66, 66, 64));
	this->closeCheckboxPanel.setOutlineColor(sf::Color::Black);
	this->closeCheckboxPanel.setOutlineThickness(2.0f);
}

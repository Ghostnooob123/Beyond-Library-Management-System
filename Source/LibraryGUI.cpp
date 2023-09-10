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

	this->initBLMS_BooksPanel();
	this->initBLMS_BooksView();
	this->initBLMS_YourListPanel();
	this->initBLMS_newLine();
	this->initBLMS_addNewBookBar();
	this->initBLMS_userInputText();
	this->initBLMS_printBookText();

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
const bool LibraryGUI::requestCheckBoxColor() const
{
	return this->isColorPicker;
}
const bool LibraryGUI::requestShowFilters() const
{
	return this->showFilters;
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
	  - This button handles opening and closing the library list.
	*/
	float buttonWidth = 10.0f;
	float buttonHeight = 65.0f;

	if (this->openLibraryButton.getGlobalBounds().contains(mousePosView))
	{
		this->openLibraryButton.setPosition(sf::Vector2f(centerX - 1125.0f, centerY - 550.0f));

		buttonWidth = 30.0f;
		buttonHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonOpenLibrary.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonOpenLibrary.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonOpenLibrary.setOutlineThickness(2.0f);
		this->highLighter_ButtonOpenLibrary.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonOpenLibrary.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
		this->highLighter_ButtonOpenLibrary.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
		this->highLighter_ButtonOpenLibrary.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
		this->highLighter_ButtonOpenLibrary.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
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
		this->highLighter_ButtonOpenLibrary.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
		this->highLighter_ButtonOpenLibrary.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
		this->highLighter_ButtonOpenLibrary.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
		this->highLighter_ButtonOpenLibrary.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
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
	target->draw(this->openLibraryButton);
	target->draw(this->UI_OpenLibraryButton);
	target->draw(this->highLighter_ButtonOpenLibrary);
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

	float buttonWidth = 10.0f;
	float buttonHeight = 65.0f;

	if (this->addBookButton.getGlobalBounds().contains(mousePosView))
	{
		this->addBookButton.setPosition(sf::Vector2f(centerX - 1125.0f, centerY - 450.0f));

		buttonWidth = 30.0f;
		buttonHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonAddBook.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonAddBook.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonAddBook.setOutlineThickness(2.0f);
		this->highLighter_ButtonAddBook.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonAddBook.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
		this->highLighter_ButtonAddBook.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
		this->highLighter_ButtonAddBook.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
		this->highLighter_ButtonAddBook.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
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
		this->highLighter_ButtonAddBook.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
		this->highLighter_ButtonAddBook.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
		this->highLighter_ButtonAddBook.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
		this->highLighter_ButtonAddBook.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
		this->highLighter_ButtonAddBook.setPosition(sf::Vector2f(centerX - 1000.0f, centerY - 450.0f));
	}

	if (this->addBookButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->addBook = true;
		this->showFilters = false;
	}

	if (this->addBook)
	{
		this->addBookBar.setPosition(sf::Vector2f(centerX - 960.0f, centerY - 350.0f));
	}
}
void LibraryGUI::renderBLMS_ButtonAddBook(sf::RenderTarget* target, std::unordered_map<unsigned, sf::Text>& newBookInput_Storage)
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
		target->draw(this->userInputText);
		for (auto& newBook : newBookInput_Storage)
		{
			newBook.second.setPosition(sf::Vector2f(this->addBookBar.getPosition().x + 265.0f, this->addBookBar.getPosition().y + 285.0f));
			target->draw(newBook.second);
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

	float buttonWidth = 10.0f;
	float buttonHeight = 65.0f;

	if (this->exitButton.getGlobalBounds().contains(mousePosView))
	{
		this->exitButton.setPosition(sf::Vector2f(centerX - 1180.0f, centerY + 50.0f));

		buttonWidth = 30.0f;
		buttonHeight = 65.0f;
		//Highlither UI by default
		this->highLighter_ButtonExit.setFillColor(sf::Color(227, 107, 211));
		this->highLighter_ButtonExit.setOutlineColor(sf::Color::Black);
		this->highLighter_ButtonExit.setOutlineThickness(2.0f);
		this->highLighter_ButtonExit.setPointCount(4);
		//Highlither UI width & height by default
		this->highLighter_ButtonExit.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
		this->highLighter_ButtonExit.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
		this->highLighter_ButtonExit.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
		this->highLighter_ButtonExit.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
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
		this->highLighter_ButtonExit.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
		this->highLighter_ButtonExit.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
		this->highLighter_ButtonExit.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
		this->highLighter_ButtonExit.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
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
	target->draw(this->UI_exitButton);
	target->draw(this->highLighter_ButtonExit);
}

   //Filter button Update & Render methods
void LibraryGUI::updateBLMS_FilterButton(sf::Vector2f& mousePosView, float& centerX, float& centerY)
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
		this->filterButton.setPosition(sf::Vector2f(centerX - 913.0f, centerY - 60.0f));

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
		this->highLighter_ButtonFilter.setPosition(sf::Vector2f(centerX - 1010.0f, centerY - 60.0f));
	}
	else
	{
		this->filterButton.setPosition(sf::Vector2f(centerX - 913.0f, centerY - 60.0f));

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
		this->highLighter_ButtonFilter.setPosition(sf::Vector2f(centerX - 1000.0f, centerY - 60.0f));
	}

	if (this->filterButton.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->showFilters = true;
	}
}
void LibraryGUI::renderBLMS_FilterButton(sf::RenderTarget* target)
{
	/*
	  @return void
	  - Display Filter button :
	  Display Filter button UI, highlighter.
	*/

	target->draw(this->filterButton);
	target->draw(this->UI_filterButton);
	target->draw(this->highLighter_ButtonFilter);
}

   //Books panel Update & Render methods
void LibraryGUI::updateBLMS_BooksPanel()
{
	/*
	  @return void

	*/
}
void LibraryGUI::renderBLMS_BooksPanel(sf::RenderTarget* target, std::unordered_map<unsigned, sf::Text>& books_Storage, sf::Vector2f& mousePosView, std::vector<sf::RectangleShape>& checkBoxes, sf::RectangleShape& checkBox)
{
	/*
	  @return void
	  - Display Books panel.
	  - Display books panel view.
	  - Polling events.
	  - Display books storage elements.
	*/

	// Set the active view to the BooksPanel's viewport


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

		//Adjust the book's position using the scrollPosition
		books_Storage[book].setPosition(sf::Vector2f(
			this->booksPanel.getPosition().x + 100.0f, 
			this->booksPanel.getPosition().y + 18.0f + this->moveDown - this->scrollPosition
		));

		//Adjust the book's position using the scrollPosition
		checkBoxes[book].setPosition(sf::Vector2f(
			this->booksPanel.getPosition().x + 10.0f,
			this->booksPanel.getPosition().y + 19.0f + this->moveDown - this->scrollPosition
		));

		std::ifstream inputFile("BOOKS_STORAGE_CHECK.txt");
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

			if (books_Storage[book].getString() == tempText.getString())
			{
				if (color == "green")
				{
					checkBoxes[book].setFillColor(sf::Color::Green);
				}
				if (color == "yellow")
				{
					checkBoxes[book].setFillColor(sf::Color::Yellow);
				}
				if (color == "red")
				{
					checkBoxes[book].setFillColor(sf::Color::Red);
				}
			}
		}
		inputFile.close();

		if (!books_Storage[book].getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			books_Storage[book].setFillColor(sf::Color::Black);
			target->draw(books_Storage[book]);
		}
		if (!checkBoxes[book].getGlobalBounds().intersects(this->yourListPanel.getGlobalBounds()))
		{
			if (checkBoxes[book].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				checkBoxes[book].setFillColor(this->colorChanger);

				std::ifstream inputFileColor("BOOKS_STORAGE_CHECK.txt");
				if (!inputFileColor)
				{
					std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
					return; // Exit early if unable to open the input file.
				}

				std::string name;
				name = books_Storage[book].getString();
				std::string color;
				if (this->colorChanger == sf::Color::Green)
				{
					color = "green";
				}
				else if (this->colorChanger == sf::Color::Yellow)
				{
					color = "yellow";
				}
				else if (this->colorChanger == sf::Color::Red)
				{
					color = "red";
				}
				else
				{
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

				// Add the new book with the updated color.
				outputFile << color << " - " << name << '\n';

				outputFile.close();
			}
			checkBoxes[book].setOutlineColor(sf::Color::Black);
			target->draw(checkBoxes[book]);
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


//Filters
void LibraryGUI::updateBLMS_Filters(sf::Vector2f& mousePosView)
{
	if (this->checkFilter.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isColorPicker = true;
	}
}
void LibraryGUI::renderBLMS_Filters(sf::RenderTarget* target)
{
	target->draw(this->checkFilter);
	target->draw(this->UI_checkFilter);
}

void LibraryGUI::updateBLMS_CheckboxPanel(sf::Vector2f& mousePosView)
{
	for (size_t i = 0; i < this->checks.size(); ++i)
	{
		if (checks[i].getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->colorChanger = checks[i].getFillColor();
		}
	}

	if (this->closeCheckboxPanel.getGlobalBounds().contains(mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isColorPicker = false;
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

	//this->isColorPicker = false; WIP
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
	this->UI_OpenLibraryButton.setString(" Open your list ");
	this->UI_OpenLibraryButton.setPosition(this->openLibraryButton.getPosition().x, this->openLibraryButton.getPosition().y + 185.0f);
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
	this->UI_AddBookButton.setString(" New book ");
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
	this->UI_exitButton.setFont(this->mainFont);
	this->UI_exitButton.setFillColor(sf::Color::Black);
	this->UI_exitButton.setCharacterSize(50);
	this->UI_exitButton.setString("Exit");
	this->UI_exitButton.setPosition(this->exitButton.getPosition().x + 10.0f, this->exitButton.getPosition().y + 770.0f);
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
	this->UI_filterButton.setFont(this->mainFont);
	this->UI_filterButton.setFillColor(sf::Color::Black);
	this->UI_filterButton.setCharacterSize(40);
	this->UI_filterButton.setString("Filters");
	this->UI_filterButton.setPosition(this->filterButton.getPosition().x + 195.0f, this->filterButton.getPosition().y + 663.0f);
}

void LibraryGUI::initBLMS_BooksPanel()
{
	/*
	  @return void
	  - Initialize the books panel.
	*/

	//booksPanel by deafult
	this->booksPanel.setFillColor(sf::Color(235, 241, 245));
	this->booksPanel.setSize(sf::Vector2f(1100.0f, 15550.0f)); //Set a large height
	this->booksPanel.setOutlineColor(sf::Color::Black);
	this->booksPanel.setOutlineThickness(3.0f);
	this->booksPanel.setPosition(sf::Vector2f(330.0f, 0.0f));

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
	this->yourListPanel.setSize(sf::Vector2f(1100.0f, 60.0f));
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
	line.setSize(sf::Vector2f(1100.0f, 2.0f));
	line.setFillColor(sf::Color::Black);
}
void LibraryGUI::initBLMS_addNewBookBar()
{
	/*
	  @return void
	  - Initialize the add new book bar.
	*/

	float addBarWidth = 350.0f;
	float addBarHeight = 60.0f;

	//addNewBookBar by default
	this->addBookBar.setFillColor(sf::Color(252, 252, 250));
	this->addBookBar.setOutlineColor(sf::Color::Black);
	this->addBookBar.setOutlineThickness(2.5f);
	this->addBookBar.setPointCount(4);
	//addNewBookBar width & height by default
	this->addBookBar.setPoint(0, sf::Vector2f(400 - addBarWidth / 2, 300 - addBarHeight / 2)); // Top-left
	this->addBookBar.setPoint(1, sf::Vector2f(400 + addBarWidth / 2, 300 - addBarHeight / 2)); // Top-right
	this->addBookBar.setPoint(2, sf::Vector2f(450 + addBarWidth / 2, 300 + addBarHeight / 2)); // Bottom-right
	this->addBookBar.setPoint(3, sf::Vector2f(450 - addBarWidth / 2, 300 + addBarHeight / 2)); // Bottom-left
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

void LibraryGUI::initBLMS_Filters()
{
	this->checkFilter.setFillColor(sf::Color(235, 241, 245));
	this->checkFilter.setOutlineColor(sf::Color::Black);
	this->checkFilter.setOutlineThickness(1.0f);
	this->checkFilter.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 310.0f, this->booksPanel.getPosition().y + 400.0f));
	this->checkFilter.setSize(sf::Vector2f(100.0f, 30.0f));

	//Filter button UI
	this->UI_checkFilter.setFont(this->mainFont);
	this->UI_checkFilter.setFillColor(sf::Color::Black);
	this->UI_checkFilter.setCharacterSize(15);
	this->UI_checkFilter.setString("check marks");
	this->UI_checkFilter.setPosition(this->checkFilter.getPosition().x + 2.0f, this->checkFilter.getPosition().y + 5.0f);
}
void LibraryGUI::initBLMS_CheckboxPanel()
{
	this->checkboxPanel.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 280.0f, this->booksPanel.getPosition().y + 30.0f));
	this->checkboxPanel.setSize(sf::Vector2f(230.0f, 100.0f));
	this->checkboxPanel.setFillColor(sf::Color(235, 241, 245));
	this->checkboxPanel.setOutlineColor(sf::Color::Black);
	this->checkboxPanel.setOutlineThickness(2.5f);

	float moveRight{ 0.0f };

	for (int i = 0; i < 3; ++i)
	{
		sf::RectangleShape check;
		if (i == 0)
		{
			check.setFillColor(sf::Color::Green);
		}
		if (i == 1)
		{
			check.setFillColor(sf::Color::Yellow);
		}
		if (i == 2)
		{
			check.setFillColor(sf::Color::Red);
		}
		check.setOutlineColor(sf::Color::Black);
		check.setPosition(sf::Vector2f(this->booksPanel.getPosition().x - 265.0f + moveRight, this->booksPanel.getPosition().y + 60.0f));
		moveRight += 80.0f;
		check.setOutlineThickness(2.5f);
		check.setSize(sf::Vector2f(40.0f, 40.0f));
		this->checks.push_back(check);
	}

	this->closeCheckboxPanel.setPosition(sf::Vector2f(this->checkboxPanel.getPosition().x + 220.0f, this->checkboxPanel.getPosition().y - 5.0f));
	this->closeCheckboxPanel.setRadius(8.0f);
	this->closeCheckboxPanel.setFillColor(sf::Color(66, 66, 64));
	this->closeCheckboxPanel.setOutlineColor(sf::Color::Black);
	this->closeCheckboxPanel.setOutlineThickness(2.0f);
}

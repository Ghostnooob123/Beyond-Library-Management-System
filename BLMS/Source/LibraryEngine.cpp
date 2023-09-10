#include "LibraryEngine.h"

// Constructor & Destructor
LibraryEngine::LibraryEngine()
{
	//Initialize member variables
	this->initVariables();
	//Initialize the window
	this->initWindow();
	//Initialize the BLMS logo
	this->initBLMS_LOGO();
}
LibraryEngine::~LibraryEngine()
{
	//Clean up allocated resources
	delete this->window;
	delete this->libraryGUI;
}

// Accessors
const bool LibraryEngine::isAppRunning() const
{
	/*
	  @return const bool
	  - Check if the application is still running.
	*/
	return this->window->isOpen();
}

// Public Engine functions
void LibraryEngine::update()
{
	/*
	  @return void
	  - Poll events.
	  - Update mouse position.
	  - Update important buttons.
	  - Update books panel.
	*/
	this->updateLibrary();
	this->pollEvents();
	this->updateMousePos();

	//Update GUI buttons
	this->libraryGUI->updateBLMS_ButtonOpenLibrary(this->mousePosView, this->centerX, this->centerY);
	this->libraryGUI->updateBLMS_ButtonAddBook(this->mousePosView, this->centerX, this->centerY);
	this->libraryGUI->updateBLMS_ButtonExit(this->mousePosView, this->centerX, this->centerY);

	if (this->libraryGUI->requestOpenLibrary())
	{
		//Update the books panel if requested
		this->libraryGUI->updateBLMS_BooksPanel();
		this->libraryGUI->updateBLMS_FilterButton(this->mousePosView, this->centerX, this->centerY);
		if (this->libraryGUI->requestShowFilters())
		{
			this->libraryGUI->updateBLMS_Filters(this->mousePosView);
		}
		if (this->libraryGUI->requestCheckBoxColor())
		{
			this->libraryGUI->updateBLMS_CheckboxPanel(this->mousePosView);
		}
	}
	if (this->libraryGUI->requestExit())
	{
		//Close the window if exit is requested
		this->window->close();
	}
}
void LibraryEngine::render()
{
	/*
	  @return void
	  - Clear old frames.
	  - Display important buttons.
	  - Display books panel.
	  - Display frame in the window.
	*/

	//Clear the window
	this->window->clear(sf::Color(255, 156, 242));

	//Render GUI buttons
	this->libraryGUI->renderBLMS_ButtonOpenLibrary(this->window);
	this->libraryGUI->renderBLMS_ButtonAddBook(this->window, this->newBookInput_Storage);

	this->libraryGUI->renderBLMS_ButtonExit(this->window);

	if (this->libraryGUI->requestOpenLibrary())
	{
		if (!this->libraryGUI->requestAddBook())
		{
			//Render the books panel if requested
			this->libraryGUI->renderBLMS_BooksPanel(this->window, this->books_Storage, this->mousePosView, this->checkBoxes, this->checkBox);
			this->libraryGUI->renderBLMS_FilterButton(this->window);
			if (this->libraryGUI->requestShowFilters())
			{
				this->libraryGUI->renderBLMS_Filters(this->window);
			}
			if (this->libraryGUI->requestCheckBoxColor())
			{
				this->libraryGUI->renderBLMS_CheckboxPanel(this->window);
			}
		}
	}
	else
	{
		//Render the logo sprite if not in the library view
		this->window->draw(this->sprite);
	}

	//Display the updated frame
	this->window->display();
}

//Private Engine functions
void LibraryEngine::pollEvents()
{
	while (this->window->pollEvent(this->eventAction))
	{
		switch (this->eventAction.type)
		{
		case sf::Event::TextEntered:
			if (this->libraryGUI->requestAddBook())
			{
				if (this->eventAction.text.unicode < 128) {
					if (this->eventAction.text.unicode == '\b' && !userInputString.empty()) {
						//Handle backspace (remove last character)
						userInputString.pop_back();
					}
					else if (this->eventAction.text.unicode == '\r') { // Enter key pressed
						//Clear the input string for new input when Enter is pressed
						//Save the input as new book and add it to the storage.
						userInputString.clear();
						std::string tempStr;
						for (auto& newBook : this->newBookInput_Storage)
						{
							tempStr += newBook.second.getString();
						}
						sf::Text userInputText = this->libraryGUI->printBook();
						userInputText.setString(tempStr);
						bool sameName{ false };
						for (auto it = this->books_Storage.begin(); it != this->books_Storage.end(); ) {
							if (it->second.getString() == userInputText.getString()) {
								sameName = true;
							}
							++it; // Move to the next entry
						}
						if (!sameName)
						{
							std::ofstream outputFile("BOOKS_STORAGE.txt", std::ios::app);
							if (!outputFile)
							{
								std::cerr << "[ERROR] can't open BOOKS_STORAGE.txt\n";
							}
							outputFile << tempStr << '\n';
							outputFile.close();

							this->books_Storage[++this->ID] = userInputText;
						}

						this->newBookInput_Storage.clear();
						this->libraryGUI->changeRequestAddBook();
					}
					else {
						//Append the entered character to the input string
						userInputString += static_cast<char>(this->eventAction.text.unicode);
						++this->charsOnLine;
					}

					//Update the text in the GUI
					sf::Text userInputText = this->libraryGUI->userInput();
					userInputText.setString(userInputString);
					this->newBookInput_Storage[this->ID] = userInputText;
				}
			}
			break;
		}
	}
}
void LibraryEngine::updateMousePos()
{
	/*
	  @return void

	  - Update mouse postitions:
	  - Mouse position relative to window.
	*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
void LibraryEngine::updateLibrary()
{
	std::ifstream inputFile("BOOKS_STORAGE.txt");
	if (!inputFile)
	{
		std::cerr << "[ERROR] can't open BOOKS_STORAGE.txt\n";
	}

	std::ifstream inputFileColor("BOOKS_STORAGE_CHECK.txt");
	if (!inputFileColor)
	{
		std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
	}

	std::set<std::string> uniqueStrings;
	std::string str;

	while (std::getline(inputFileColor, str)) {
		uniqueStrings.insert(str);
	}

	inputFileColor.close();

	std::ofstream outputFile("BOOKS_STORAGE_CHECK.txt", std::ios::out | std::ios::trunc);
	if (!outputFile)
	{
		std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
	}
	outputFile.close();

	outputFile.open("BOOKS_STORAGE_CHECK.txt", std::ios::app);
	if (!outputFile)
	{
		std::cerr << "[ERROR] can't open BOOKS_STORAGE_CHECK.txt\n";
	}

	for (auto& uniqueString : uniqueStrings) {
		outputFile << uniqueString << '\n';
	}
	outputFile.close();

	std::string line;
	while (std::getline(inputFile, line)) {
		if (line == "")
		{
			continue;
		}

		sf::Text userInputText = this->libraryGUI->printBook();
		userInputText.setString(line);

		bool sameName{ false };

		for (auto it = this->books_Storage.begin(); it != this->books_Storage.end(); ) {
			if (it->second.getString() == userInputText.getString()) {
				sameName = true;
			}
			++it; // Move to the next entry
		}

		if (!sameName)
		{
			this->books_Storage[++ID] = userInputText;
		}
	}

	inputFile.close();
}

//Private functions
void LibraryEngine::initVariables()
{
	this->window = nullptr;
	this->ID = 0;
	this->updateOnStart = false;

	this->maxCharsOnLine = 10;
	this->charsOnLine = 0;
}
void LibraryEngine::initWindow()
{
	this->videoMode.height = 1500;
	this->videoMode.width = 900;

	this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode.height, this->videoMode.width), "", sf::Style::None | sf::Style::Resize);
	this->window->setPosition(sf::Vector2i(200, 50));
	this->window->setFramerateLimit(165);

	//Centers of the screen
	this->centerX = this->window->getSize().x / 2.0f;
	this->centerY = this->window->getSize().y / 2.0f;

	this->libraryGUI->setWindow(this->window);
}
void LibraryEngine::initBLMS_LOGO()
{
	if (!this->texture.loadFromFile("Source/Textures/Books_logo.png"))
	{
		std::cerr << "[ERROR] can't open [Source/Textures/Books_logo.png]" << '\n';
	}

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(sf::Vector2f(this->centerX - 600.0f, this->centerY - 450.0f));
	this->sprite.setScale(sf::Vector2f(6.0f, 6.0f));
}

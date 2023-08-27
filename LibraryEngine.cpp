#include "LibraryEngine.h"

//Constructor & Destructor
LibraryEngine::LibraryEngine()
{
	this->initVariables();
	this->initWindow();
	this->initBLMS_ButtonOpenLibrary();
	this->initBLMS_ButtonAddBook();
	this->initBLMS_ButtonExit();
	this->initBLMS_BooksPanel();
}
LibraryEngine::~LibraryEngine()
{
	delete this->window;
}

//Accessors
const bool LibraryEngine::isAppRunning() const
{
	return this->window->isOpen();
}

//Public Engine functions
void LibraryEngine::update()
{
	/*
	  @return void
	  - Poll events.
	  - Update mouse position.
	  - Update important buttons.
	  - Update books panel.
	*/
	this->pollEvents();
	this->updateMousePos();

	this->updateBLMS_ButtonOpenLibrary();
	this->updateBLMS_ButtonAddBook();

	this->updateBLMS_ButtonExit();

	if (this->isLibraryOpen)
	{
		this->updateBLMS_BooksPanel();
	}
}
void LibraryEngine::render()
{
	/*
	  @return void
	  - Clear old frames.
	  - Display important buttons.
	  - Display books panel.
	  - Display frame in window.
	*/
	this->window->clear(sf::Color(114, 51, 181));

	this->renderBLMS_ButtonOpenLibrary(this->window);
	this->renderBLMS_ButtonAddBook(this->window);

	this->renderBLMS_ButtonExit(this->window);

	if (this->isLibraryOpen)
	{
		this->renderBLMS_BooksPanel(this->window);
	}

	this->window->display();
}

//Private Engine functions
void LibraryEngine::pollEvents()
{
	while (this->window->pollEvent(this->eventAction))
	{
		switch (this->eventAction.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				this->window->close();
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
//Open Library Update & Render methods
void LibraryEngine::updateBLMS_ButtonOpenLibrary()
{
	if (this->openLibraryButton.getGlobalBounds().contains(this->mousePosView))
	{
		this->openLibraryButton.setPosition(sf::Vector2f(this->centerX - 1100.0f, this->centerY - 550.0f));
	}
	else
	{
		this->openLibraryButton.setPosition(sf::Vector2f(this->centerX - 1150.0f, this->centerY - 550.0f));
	}

	if (this->openLibraryButton.getGlobalBounds().contains(this->mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->isLibraryOpen = true;
	}
}
void LibraryEngine::renderBLMS_ButtonOpenLibrary(sf::RenderTarget* target)
{
	target->draw(this->openLibraryButton);
}
//Add book Update & Render methods
void LibraryEngine::updateBLMS_ButtonAddBook()
{
	if (this->addBookButton.getGlobalBounds().contains(this->mousePosView))
	{
		this->addBookButton.setPosition(sf::Vector2f(this->centerX - 1100.0f, this->centerY - 450.0f));
	}
	else
	{
		this->addBookButton.setPosition(sf::Vector2f(this->centerX - 1150.0f, this->centerY - 450.0f));
	}
}
void LibraryEngine::renderBLMS_ButtonAddBook(sf::RenderTarget* target)
{
	target->draw(this->addBookButton);
}
//Exit button Update & Render methods
void LibraryEngine::updateBLMS_ButtonExit()
{
	if (this->exitButton.getGlobalBounds().contains(this->mousePosView))
	{
		this->exitButton.setPosition(sf::Vector2f(this->centerX - 1100.0f, this->centerY + 50.0f));
	}
	else
	{
		this->exitButton.setPosition(sf::Vector2f(this->centerX - 1150.0f, this->centerY + 50.0f));
	}

	if (this->exitButton.getGlobalBounds().contains(this->mousePosView) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->window->close();
	}
}
void LibraryEngine::renderBLMS_ButtonExit(sf::RenderTarget* target)
{
	target->draw(this->exitButton);
}
//Books panel Update & Render methods
void LibraryEngine::updateBLMS_BooksPanel()
{

}
void LibraryEngine::renderBLMS_BooksPanel(sf::RenderTarget* target)
{
	target->draw(this->booksPanel);
}

//Private functions
void LibraryEngine::initVariables()
{
	this->window = nullptr;
	this->isLibraryOpen = false;
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
}
void LibraryEngine::initBLMS_ButtonOpenLibrary()
{
	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//add Book button by default
	this->openLibraryButton.setFillColor(sf::Color(235, 241, 245));
	this->openLibraryButton.setPointCount(4);
	//add Book button width & height by default
	this->openLibraryButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->openLibraryButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->openLibraryButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->openLibraryButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
}
void LibraryEngine::initBLMS_ButtonAddBook()
{
	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//add Book button by default
	this->addBookButton.setFillColor(sf::Color(235, 241, 245));
	this->addBookButton.setPointCount(4);
	//add Book button width & height by default
	this->addBookButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->addBookButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->addBookButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->addBookButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
}
void LibraryEngine::initBLMS_ButtonExit()
{
	float buttonWidth = 300.0f;
	float buttonHeight = 65.0f;

	//add Book button by default
	this->exitButton.setFillColor(sf::Color(235, 241, 245));
	this->exitButton.setPointCount(4);
	//add Book button width & height by default
	this->exitButton.setPoint(0, sf::Vector2f(400 - buttonWidth / 2, 300 - buttonHeight / 2)); // Top-left
	this->exitButton.setPoint(1, sf::Vector2f(400 + buttonWidth / 2, 300 - buttonHeight / 2)); // Top-right
	this->exitButton.setPoint(2, sf::Vector2f(450 + buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-right
	this->exitButton.setPoint(3, sf::Vector2f(450 - buttonWidth / 2, 300 + buttonHeight / 2)); // Bottom-left
}
void LibraryEngine::initBLMS_BooksPanel()
{
	this->booksPanel.setFillColor(sf::Color(235, 241, 245));
	this->booksPanel.setSize(sf::Vector2f(1000.0f, 850.0f));
	this->booksPanel.setPosition(sf::Vector2f(this->centerX - 320.0f, this->centerY - 420.0f));
}

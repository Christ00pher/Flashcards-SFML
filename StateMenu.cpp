#include "StateMenu.h"
StateMenu::StateMenu(Flashcards &flashcards, Window &window)
:TOTAL_BUTTONS(4),
 start("data/StateStart/startDefault.png", "data/StateStart/startMarked.png",{400,80}),
 manage("data/StateStart/handleDefault.png", "data/StateStart/handleMarked.png",{400,2*80}),
 options("data/StateStart/optionsDefault.png", "data/StateStart/optionsMarked.png",{400,3*80}),
 exit("data/StateStart/exitDefault.png", "data/StateStart/exitMarked.png",{400,4*80})
{
	//setting pointer to the flashcards object
	this->flashcards = &flashcards;
	this->window = &window;
	
	leftClick = false;
	end = false;
}

void StateMenu::update()
{
	pollEvent();
}

void StateMenu::render()
{
	window->startRender();
	window->draw(background);
	
	window->draw(start.getSprite());
	window->draw(manage.getSprite());
	window->draw(options.getSprite());
	window->draw(exit.getSprite());
	
	window->finishRender();
}

bool StateMenu::isMouseReleased(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left &&
		event.type == sf::Event::MouseButtonReleased)
			return true;
	
	return false;
}

bool StateMenu::clickOnButton(sf::Sprite& but)
{
	sf::Vector2f buttonPos = but.getPosition();
	if (leftClickPos.x >= buttonPos.x && leftClickPos.x <= buttonPos.x + 400
		&& leftClickPos.y >= buttonPos.y && leftClickPos.y <= buttonPos.y + 60)
			return true;
			
	return false;
}

//function checks if the button has to be highlighted, handled or extinguished
void StateMenu::checkButtons(sf::Event event)
{
	start.checkCollision( event, window );
	manage.checkCollision( event, window );
	options.checkCollision( event, window );
	exit.checkCollision( event, window );
}

//functions is checking if changing state is needed or if the app has to be closed
void StateMenu::handleClick(sf::Sprite& but)
{
	
}

void StateMenu::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
			leftClick = false;
			
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !leftClick)
		{
			leftClickPos = sf::Mouse::getPosition( *(window->getWindow()) );
			leftClick = true;
		}
		
		checkButtons(event);
		
		if (event.type == sf::Event::Closed)
		{
			window->closeWindow();
			end = true;
		}
	}
}
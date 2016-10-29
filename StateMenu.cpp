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

//functions is checking if changing state is needed or if the app has to be closed
void StateMenu::handleClickExit()
{
	window->closeWindow();
	end = true;
}

void StateMenu::handleClickStart()
{
	stateStart = true;
}

void StateMenu::handleClickManage()
{
	stateManage = true;
}

void StateMenu::handleClickOptions()
{
	stateOptions = true;
}

void StateMenu::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		checkButtons(event);
		
		if (event.type == sf::Event::Closed)
		{
			window->closeWindow();
			end = true;
		}
	}
}

//function checks if the button has to be highlighted, handled or extinguished
void StateMenu::checkButtons(sf::Event event)
{
	start.checkCollision( event, window );
	manage.checkCollision( event, window );
	options.checkCollision( event, window );
	exit.checkCollision( event, window );
	
	if (start.clickOnButton())
		handleClickStart();
		
	if (manage.clickOnButton())
		handleClickManage();
		
	if (options.clickOnButton())
		handleClickOptions();
		
	if (exit.clickOnButton())
		handleClickExit();
}
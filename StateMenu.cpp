#include "StateMenu.h"
#include <iostream>
StateMenu::StateMenu(Flashcards &flashcards, Window &window) :
TOTAL_BUTTONS(4)
{
	//setting pointer to the flashcards object
	this->flashcards = &flashcards;
	this->window = &window;
	
	
	//setting string paths to the resources
	button[Start].defaultPath = "data/StateStart/startDefault.png";
	button[Start].markedPath = "data/StateStart/startMarked.png";
	button[Handle].defaultPath = "data/StateStart/handleDefault.png";
	button[Handle].markedPath = "data/StateStart/handleMarked.png";
	button[Options].defaultPath = "data/StateStart/optionsDefault.png";
	button[Options].markedPath = "data/StateStart/optionsMarked.png";
	button[Exit].defaultPath = "data/StateStart/exitDefault.png";
	button[Exit].markedPath = "data/StateStart/exitMarked.png";
	
	//assigning textures to sprites
	for (int i = 0; i < TOTAL_BUTTONS; ++i)
	{
		button[i].t_button.loadFromFile(button[i].defaultPath);
		button[i].button.setTexture(button[i].t_button);
		button[i].button.setPosition(200, (i+1) * 80);
	}
	
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
	for (int i = 0; i < TOTAL_BUTTONS; i++)
	{
		window->draw(button[i].button);
	}
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

//function is checking if the button has to be highlighted, handled or extinguished
void StateMenu::checkButtons(sf::Event event)
{
	//for (sf::Sprite x: button) //add &
		
	for (int i = 0; i < TOTAL_BUTTONS; i++)
	{
		if (mouseOnButton(button[i].button))
		{
			highlightButton(i);
		}
		
		if (clickOnButton(button[i].button) && isMouseReleased(event) && mouseOnButton(button[i].button))
		{
			handleClick(button[i].button);
		}
		
		if (!mouseOnButton(button[i].button))
		{
			undo(i);
		}
	}
}

bool StateMenu::mouseOnButton(sf::Sprite &but)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition( *(window->getWindow()) );
	sf::Vector2f buttonPos = but.getPosition();
	
	if (mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + 400
		&& mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + 60)
			return true;
	
	return false;
}

//functions is checking if changing state is needed or if the app has to be closed
void StateMenu::handleClick(sf::Sprite& but)
{
	if (&but == &button[Start].button)
	{
		stateStart = true;
	}
	
	else if (&but == &button[Handle].button)
	{
		stateHandle = true;
	}
	
	else if (&but == &button[Options].button)
	{
		stateOptions = true;
	}
	
	else if (&but == &button[Exit].button)
	{
		end = true;
		window->closeWindow();
	}
	stateMenu = false;
}

void StateMenu::highlightButton(int i)
{
	button[i].t_button.loadFromFile(button[i].markedPath);
	button[i].button.setTexture(button[i].t_button);
}

void StateMenu::undo(int i)
{
	button[i].t_button.loadFromFile(button[i].defaultPath);
	button[i].button.setTexture(button[i].t_button);
}

void StateMenu::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
			leftClick = !leftClick;
			
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !leftClick)
		{
			leftClickPos = sf::Mouse::getPosition( *(window->getWindow()) );
			leftClick = !leftClick;
		}
		
		checkButtons(event);
		
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode == 13)
			{
				flashcards->add(string);
				flashcards->show();
				string.clear();
			}
			
			else if (event.text.unicode < 128)
			{
				if (string.isEmpty())
				{
					if (event.text.unicode != 8)
						string += event.text.unicode;
				}
				else 
						string += event.text.unicode;
			}
				
		}
		
		if (event.type == sf::Event::Closed)
		{
			end = true;
			window->closeWindow();
		}
	}
}
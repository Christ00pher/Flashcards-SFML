#include "IState.h"
#include <iostream>

IState::IState()
{
	end = false;
	stateMenu = false;
	stateManage = false;
	stateOptions = false;
	stateStart = false;
	t_background.loadFromFile("data/bg1.jpg");
	background.setTexture(t_background);
}

void IState::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->closeWindow();
	}
}

bool IState::toExit() { return end; }

bool IState::getStateMenu() { return stateMenu; }
bool IState::getStateManage() { return stateManage; }
bool IState::getStateOptions() { return stateOptions; }
bool IState::getStateStart() { return stateStart; }

//bool IState::isActive() { return true; }

bool IState::toReturn(sf::Event event)
{
	if (event.type == sf::Event::Closed)
			window->closeWindow();
			
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			stateMenu = true;
	}
	
	return stateMenu;
}
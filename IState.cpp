#include "IState.h"
#include <iostream>

IState::IState(Flashcards &flashcards)
{
	this->flashcards = &flashcards;
	end = false;
}

void IState::pollEvent()
{
	sf::Event event;
	while (window.getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.closeWindow();
	}
}

bool IState::getMenu() { return stateMenu; }
bool IState::getStart() { return stateStart; }
bool IState::getHandle() { return stateHandle; }
bool IState::getOptions() { return stateOptions; }

bool IState::toExit()
{
	return end;
}
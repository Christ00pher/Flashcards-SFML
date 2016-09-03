#include "IState.h"
#include <iostream>

IState::IState(Flashcards &flashcards)
{
	this->flashcards = &flashcards;
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
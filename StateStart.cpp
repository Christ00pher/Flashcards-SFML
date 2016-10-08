#include "StateStart.h"

StateStart::StateStart(Flashcards& flashcards, Window& window)
{
	this->window = &window;
	this->flashcards = &flashcards;
}

StateStart::~StateStart() {}

void StateStart::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (toReturn(event))
			break;
	}
}

void StateStart::render()
{
	window->startRender();
	window->draw(background);
	window->finishRender();
}

void StateStart::update()
{
	pollEvent();
}


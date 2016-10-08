#include "StateStart.h"

StateStart::StateStart(Flashcards& flashcards, Window& window)
:tbPolish(window, window.getX() / 4, window.getY() / 3),
 tbEnglish(window, 3 * window.getX() / 4, window.getY() / 3),
 cPolish("Polish word", window.getX() / 4, window.getY() / 4),
 cEnglish("English translation", 3 * window.getX() / 4, window.getY() / 4)
{
	this->window = &window;
	this->flashcards = &flashcards;
	tbEnglish.mark();
}

StateStart::~StateStart() {}

void StateStart::pollEvent()
{
	bool toCheck;
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (toReturn(event))
			break;
		
		tbEnglish.getInput(event,toCheck);
	}
}

void StateStart::render()
{
	window->startRender();
	window->draw(background);
	window->draw(cPolish.getText());
	window->draw(cEnglish.getText());
	tbPolish.draw();
	tbEnglish.draw();
	window->finishRender();
}

void StateStart::update()
{
	pollEvent();
}


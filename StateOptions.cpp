#include "StateOptions.h"

StateOptions::StateOptions(Flashcards& flashcards, Window &window)
:credits()
{
	//credits.setSize(100);
	credits.setPosition( window.getX()/2, window.getY()/2);
	this->flashcards = &flashcards;
	this->window = &window;
}

void StateOptions::update()
{
	pollEvent();
}

void StateOptions::render()
{
	window->startRender();
	window->draw(background);
	window->draw(credits.getText());
	window->finishRender();
}

void StateOptions::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->closeWindow();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				stateMenu = true;
		}
		
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//stateMenu = true;
			}
		}
	}
}
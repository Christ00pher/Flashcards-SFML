#include "StateStart.h"
#include <iostream>

StateStart::StateStart(Flashcards& flashcards, Window& window)
:tbPolish(window, window.getX() / 4, window.getY() / 3),
 tbEnglish(window, 3 * window.getX() / 4, window.getY() / 3),
 cPolish("Polish word", window.getX() / 4, window.getY() / 4),
 cEnglish("English translation", 3 * window.getX() / 4, window.getY() / 4)
{
	this->window = &window;
	this->flashcards = &flashcards;
	tbEnglish.mark();
	newQuestion = true;
}

StateStart::~StateStart() {}

void StateStart::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (toReturn(event))
			break;
			
		if (event.text.unicode == enter)
		{
			if ( isCorrect() )
			{
				std::cout << "Correct!" << std::endl;
			}
			else
			{
				std::cout << "Bad!" << std::endl;
			}
			
			newQuestion = true;
			tbEnglish.clear();
		}
		
		tbEnglish.getInput(event);
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
	if (newQuestion)
	{
		flashcards->ask();
		tbPolish.setString( flashcards->getQuestion() );
		newQuestion = false;
	}
	pollEvent();
}

bool StateStart::isCorrect()
{
	if (tbEnglish.getString() == flashcards->getAnswer())
		return true;
	
	return false;
}
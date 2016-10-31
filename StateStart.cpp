#include "StateStart.h"
#include <iostream>

StateStart::StateStart()
:tbPolish(Window::instance().getX() / 4, Window::instance().getY() / 3),
 tbEnglish(3 * Window::instance().getX() / 4, Window::instance().getY() / 3),
 cPolish("Polish word", Window::instance().getX() / 4, Window::instance().getY() / 4),
 cEnglish("English translation", 3 * Window::instance().getX() / 4, Window::instance().getY() / 4)
{
	tbEnglish.mark();
	newQuestion = true;
	
	cPolish.setColor(sf::Color::White);
	cEnglish.setColor(sf::Color::White);
}

StateStart::~StateStart() {}

void StateStart::pollEvent()
{
	sf::Event event;
	while (Window::instance().getWindow()->pollEvent(event))
	{
		if (toReturn(event))
			break;
		
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode < 128)
			{
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
			}
		}
		
		if (event.type == sf::Event::Closed)
		{
			Window::instance().closeWindow();
			end = true;
		}
		
		tbEnglish.getInput(event);
	}
}

void StateStart::render()
{
	Window::instance().startRender();
	Window::instance().draw(background);
	Window::instance().draw(cPolish.getText());
	Window::instance().draw(cEnglish.getText());
	tbPolish.draw();
	tbEnglish.draw();
	Window::instance().finishRender();
}

void StateStart::update()
{
	if (newQuestion)
	{
		Flashcards::instance().ask();
		tbPolish.setString( Flashcards::instance().getQuestion() );
		newQuestion = false;
	}
	pollEvent();
}

bool StateStart::isCorrect()
{
	if (tbEnglish.getString() == Flashcards::instance().getAnswer())
		return true;
	
	return false;
}
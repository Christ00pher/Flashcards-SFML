#include "StateStart.h"
#include <iostream>

StateStart::StateStart()
:tbPolish(Window::instance().getX() / 4, Window::instance().getY() / 3),
 tbEnglish(3 * Window::instance().getX() / 4, Window::instance().getY() / 3),
 cPolish("Polish word", Window::instance().getX() / 4, Window::instance().getY() / 4),
 cEnglish("English translation", 3 * Window::instance().getX() / 4, Window::instance().getY() / 4),
 back("data/General/back1.png", "data/General/back2.png")
{
	back.setPosition(float(back.getSize().x / 2), float(back.getSize().y / 2));
	
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
					handleAnswer();
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
		
		back.checkCollision(event);
		
		if (back.clickOnButton())
		{
			Sound::instance().playButtonSound();
			stateMenu = true;
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
	back.draw();
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

void StateStart::handleAnswer()
{
	if ( isCorrect() )
	{
		std::cout << "Correct!" << std::endl;
	}
	else
	{
		std::cout << "Bad!" << std::endl;
	}
}
#include "StateOptions.h"

StateOptions::StateOptions()
:credits("App written by Chris")
{
	//credits.setSize(100);
	credits.setPosition( Window::instance().getX()/2, Window::instance().getY()/2);
}

void StateOptions::update()
{
	pollEvent();
}

void StateOptions::render()
{
	Window::instance().startRender();
	Window::instance().draw(background);
	Window::instance().draw(credits.getText());
	Window::instance().finishRender();
}

void StateOptions::pollEvent()
{
	sf::Event event;
	while (Window::instance().getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			Window::instance().closeWindow();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				stateMenu = true;
		}
		
		if (event.type == sf::Event::Closed)
		{
			Window::instance().closeWindow();
			end = true;
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
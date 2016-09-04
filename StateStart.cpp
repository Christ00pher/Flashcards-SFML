#include "StateStart.h"
#include <iostream>
StateStart::StateStart(Flashcards &flashcards) :
TOTAL_BUTTONS(4)
{
	//setting pointer to the flashcards object
	this->flashcards = &flashcards;
	
	//loading .png images from the files
	t_button[Start].loadFromFile("data/StateStart/startButton.png");
	t_button[Handle].loadFromFile("data/StateStart/handleButton.png");
	t_button[Options].loadFromFile("data/StateStart/optionsButton.png");
	t_button[Exit].loadFromFile("data/StateStart/exitButton.png");
	
	//assigning textures to sprites
	for (int i = 0; i < 4; ++i)
	{
		button[i].setTexture(t_button[i]);
		button[i].setPosition(200, (i+1) * 80);
	}
	
	end = false;
}

void StateStart::update()
{
	pollEvent();
	checkButtons();
}

void StateStart::render()
{
	window.startRender();
	for (int i = 0; i < 4; i++)
	{
		window.draw(button[i]);
	}
	window.finishRender();
}

void StateStart::checkButtons()
{
	//for (sf::Sprite x: button) //add &
	for (int i = 0; i < 4; i++)
	{
		if (mouseOnButton(button[i]))
		{
			highlightButton(button[i]);
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseOnButton(button[i]))
		{
			handleClick(button[i]);
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		if (!mouseOnButton(button[i]))
		{
			undo(button[i]);
		}
	}
}

void StateStart::highlightButton(sf::Sprite &but)
{
	but.setColor(sf::Color::Green);
}

void StateStart::undo(sf::Sprite &but)
{
	but.setColor(sf::Color::White);
}

bool StateStart::mouseOnButton(sf::Sprite &but)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition( *(window.getWindow()) );
	sf::Vector2f buttonPos = but.getPosition();
	
	if (mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + 400
		&& mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + 60)
			return true;
	
	return false;
}

void StateStart::handleClick(sf::Sprite& but)
{
	if (&but == &button[Start])
	{
		//handle asking
	}
	
	else if (&but == &button[Handle])
	{
		//handle editing flashcards
	}
	
	else if (&but == &button[Options])
	{
		
	}
	
	else if (&but == &button[Exit])
	{
		end = true;
		window.closeWindow();
	}
}
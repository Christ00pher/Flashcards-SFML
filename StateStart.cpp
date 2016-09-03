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
	
	//sf::Vector2f size = button.getGlobalBounds();
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
	sf::Vector2i mPos = sf::Mouse::getPosition( *(window.getWindow()) );
	sf::Vector2f sPos;
	//for (sf::Sprite x: button) //add &
	for (int i = 0; i < 4; i++)
	{
		sPos = button[i].getPosition();
		if (mPos.x >= sPos.x && mPos.x <= sPos.x + 400
			&& mPos.y >= sPos.y && mPos.y <= sPos.y + 60)
		{
			highlightButton(button[i]);
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		sPos = button[i].getPosition();
		if (!(mPos.x >= sPos.x && mPos.x <= sPos.x + 400
			&& mPos.y >= sPos.y && mPos.y <= sPos.y + 60))
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
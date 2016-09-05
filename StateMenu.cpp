#include "StateMenu.h"
#include <iostream>
StateMenu::StateMenu(Flashcards &flashcards) :
TOTAL_BUTTONS(4)
{
	//setting pointer to the flashcards object
	this->flashcards = &flashcards;
	
	button[Start].defaultPath = "data/StateStart/startDefault.png";
	button[Start].markedPath = "data/StateStart/startMarked.png";
	button[Handle].defaultPath = "data/StateStart/handleDefault.png";
	button[Handle].markedPath = "data/StateStart/handleMarked.png";
	button[Options].defaultPath = "data/StateStart/optionsDefault.png";
	button[Options].markedPath = "data/StateStart/optionsMarked.png";
	button[Exit].defaultPath = "data/StateStart/exitDefault.png";
	button[Exit].markedPath = "data/StateStart/exitMarked.png";
	//loading .png images from the files
	/*
	t_button[Start].loadFromFile("data/StateStart/startDefault.png");
	t_button[Handle].loadFromFile("data/StateStart/handleDefault.png");
	t_button[Options].loadFromFile("data/StateStart/optionsDefault.png");
	t_button[Exit].loadFromFile("data/StateStart/exitDefault.png");
	 */
	t_background.loadFromFile("data/background.jpg");
	//assigning textures to sprites
	for (int i = 0; i < TOTAL_BUTTONS; ++i)
	{
		button[i].t_button.loadFromFile(button[i].defaultPath);
		button[i].button.setTexture(button[i].t_button);
		button[i].button.setPosition(200, (i+1) * 80);
	}
	background.setTexture(t_background);
	
	end = false;
}

void StateMenu::update()
{
	pollEvent();
	checkButtons();
}

void StateMenu::render()
{
	window.startRender();
	window.draw(background);
	for (int i = 0; i < TOTAL_BUTTONS; i++)
	{
		window.draw(button[i].button);
	}
	window.finishRender();
}

void StateMenu::checkButtons()
{
	//for (sf::Sprite x: button) //add &
	for (int i = 0; i < TOTAL_BUTTONS; i++)
	{
		if (mouseOnButton(button[i].button))
		{
			highlightButton(i);
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseOnButton(button[i].button))
		{
			handleClick(button[i].button);
		}
		
		if (!mouseOnButton(button[i].button))
		{
			undo(i);
		}
	}
}

bool StateMenu::mouseOnButton(sf::Sprite &but)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition( *(window.getWindow()) );
	sf::Vector2f buttonPos = but.getPosition();
	
	if (mousePos.x >= buttonPos.x && mousePos.x <= buttonPos.x + 400
		&& mousePos.y >= buttonPos.y && mousePos.y <= buttonPos.y + 60)
			return true;
	
	return false;
}

void StateMenu::handleClick(sf::Sprite& but)
{
	if (&but == &button[Start].button)
	{
		//handle asking
	}
	
	else if (&but == &button[Handle].button)
	{
		//handle editing flashcards
	}
	
	else if (&but == &button[Options].button)
	{
		//handle options
	}
	
	else if (&but == &button[Exit].button)
	{
		end = true;
		window.closeWindow();
	}
}

void StateMenu::highlightButton(int i)
{
	button[i].t_button.loadFromFile(button[i].markedPath);
	button[i].button.setTexture(button[i].t_button);
}

void StateMenu::undo(int i)
{
	button[i].t_button.loadFromFile(button[i].defaultPath);
	button[i].button.setTexture(button[i].t_button);
}
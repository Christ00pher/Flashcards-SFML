#include "StateMenu.h"
#include <iostream>
StateMenu::StateMenu(Flashcards &flashcards) :
TOTAL_BUTTONS(4)
{
	//setting pointer to the flashcards object
	this->flashcards = &flashcards;
	
	//loading .png images from the files
	t_button[Start].loadFromFile("data/StateStart/startDefault.png");
	t_button[Handle].loadFromFile("data/StateStart/handleDefault.png");
	t_button[Options].loadFromFile("data/StateStart/optionsDefault.png");
	t_button[Exit].loadFromFile("data/StateStart/exitDefault.png");
	t_background.loadFromFile("data/background.jpg");
	
	//assigning textures to sprites
	for (int i = 0; i < TOTAL_BUTTONS; ++i)
	{
		button[i].setTexture(t_button[i]);
		button[i].setPosition(200, (i+1) * 80);
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
		window.draw(button[i]);
	}
	window.finishRender();
}

void StateMenu::checkButtons()
{
	//for (sf::Sprite x: button) //add &
	for (int i = 0; i < TOTAL_BUTTONS; i++)
	{
		if (mouseOnButton(button[i]))
		{
			highlightButton(button[i], i);
		}
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseOnButton(button[i]))
		{
			handleClick(button[i]);
		}
		
		if (!mouseOnButton(button[i]))
		{
			undo(button[i]);
		}
	}
}

//TO DO: create Structure for each button with texture,sprite and string with path to files
//and shorten the 'undo' and 'highlightButton' function 
//ARRAY OF STRUCTURES!!!
void StateMenu::highlightButton(sf::Sprite &but, int i)
{
	if (&but == &button[Start])
	{
		t_button[Start].loadFromFile("data/StateStart/startMarked.png");
		button[Start].setTexture(t_button[Start]);
	}
	
	else if (&but == &button[Handle])
	{
		t_button[Handle].loadFromFile("data/StateStart/handleMarked.png");
		button[Handle].setTexture(t_button[Handle]);
	}
	
	else if (&but == &button[Options])
	{
		t_button[Options].loadFromFile("data/StateStart/optionsMarked.png");
		button[Options].setTexture(t_button[Options]);
	}
	
	else if (&but == &button[Exit])
	{
		t_button[Exit].loadFromFile("data/StateStart/exitMarked.png");
		button[Exit].setTexture(t_button[Exit]);
	}
}

void StateMenu::undo(sf::Sprite &but)
{
	if (&but == &button[Start])
	{
		t_button[Start].loadFromFile("data/StateStart/startDefault.png");
		button[Start].setTexture(t_button[Start]);
	}
	
	else if (&but == &button[Handle])
	{
		t_button[Handle].loadFromFile("data/StateStart/handleDefault.png");
		button[Handle].setTexture(t_button[Handle]);
	}
	
	else if (&but == &button[Options])
	{
		t_button[Options].loadFromFile("data/StateStart/optionsDefault.png");
		button[Options].setTexture(t_button[Options]);
	}
	
	else if (&but == &button[Exit])
	{
		t_button[Exit].loadFromFile("data/StateStart/exitDefault.png");
		button[Exit].setTexture(t_button[Exit]);
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
		//handle options
	}
	
	else if (&but == &button[Exit])
	{
		end = true;
		window.closeWindow();
	}
}


/*
void StateMenu::highlightButton(sf::Sprite &but, int i)
{
	button[i].t_button.loadFromFile(string_path);
	button[i].button.setTexture(t_button);
}
*/
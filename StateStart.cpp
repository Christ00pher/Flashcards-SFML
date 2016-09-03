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
}

void StateStart::update()
{
	pollEvent();
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
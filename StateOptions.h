#pragma once
#include "IState.h"
#include "Window.h"

class StateOptions : public IState
{
private:
	sf::Font font;
	sf::Text text;
public:
	StateOptions(Flashcards&,Window&);
	~StateOptions() {};
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};
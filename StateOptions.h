#pragma once
#include "IState.h"
#include "Caption.h"

class StateOptions : public IState
{
private:
	//sf::Font font;
	sf::Text text;
	Caption credits;
public:
	StateOptions(Flashcards&,Window&);
	~StateOptions() {};
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};
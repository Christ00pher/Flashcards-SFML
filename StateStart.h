#pragma once
#include "IState.h"
#include "Flashcards.h"

enum Buttons { Start, Handle, Options, Exit};

class StateStart : public IState
{
private:
	const short TOTAL_BUTTONS;
	sf::Texture t_button[4];
	sf::Sprite button[4];
public:
	StateStart(Flashcards &flashcards);
	~StateStart() {};
	virtual void update();
	virtual void render();
	
};
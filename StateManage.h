#pragma once
#include "IState.h"
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "Caption.h"

class StateManage : public IState
{
private:
	TextBox tbEnglish;
	TextBox tbPolish;
	Flashcards *flashcards;
	Window *window;
	bool isTbPolish;
	bool isTbEnglish;
	Caption c1,c2;
	
	void mark(sf::Event);
	void handleInput(sf::Event);
	bool toReturn(sf::Event);
public:
	StateManage(Flashcards&,Window&);
	~StateManage();
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};
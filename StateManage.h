#pragma once
#include "IState.h"
#include <SFML/Graphics.hpp>
#include "TextBox.h"

class StateManage : public IState
{
private:
	TextBox tbEnglish;
	TextBox tbPolish;
	bool isTbPolish;
	bool isTbEnglish;
	bool click;
	Caption c1,c2;
	
	void mark(sf::Event);
	void handleInput(sf::Event);
	bool toReturn(sf::Event);
	void remark();
	bool isCorrect();
public:
	StateManage(Flashcards&);
	~StateManage();
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};
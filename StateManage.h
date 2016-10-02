#pragma once
#include "IState.h"
#include <SFML/Graphics.hpp>
#include "TextBox.h"

class StateManage : public IState
{
private:
	TextBox tbEnglish;
	TextBox tbPolish;
	Flashcards *flashcards;
	Window *window;
	bool isTbPolish;
	bool isTbEnglish;
	sf::String polish;
	sf::String english;
	sf::Text t_polish;
	sf::Font font;
public:
	StateManage(Flashcards&,Window&);
	~StateManage();
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};
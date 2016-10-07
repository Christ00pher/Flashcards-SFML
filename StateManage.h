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
	sf::String polish;
	sf::String english;
	sf::Text t_polish;
	sf::Text t_english;
	sf::Font font;
	
	void mark(sf::Event);
	void handleInput(sf::Event);
	void toReturn(sf::Event);
public:
	StateManage(Flashcards&,Window&);
	~StateManage();
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};
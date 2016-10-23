#pragma once
#include "IState.h"
#include "Flashcards.h"

enum Buttons { Start, Handle, Options, Exit};

class StateMenu : public IState
{
private:
	const short TOTAL_BUTTONS;
	sf::Vector2f buttonSize;
	Button start;
	Button manage;
	Button options;
	Button exit;
	void highlightButton(int);
	void undo(int);
	sf::Vector2i leftClickPos;
	bool leftClick;
	sf::String string;
public:
	StateMenu(Flashcards &flashcards, Window &window);
	~StateMenu() {};
	virtual void update();
	virtual void render();
	virtual void checkButtons(sf::Event);
	virtual void pollEvent();
	bool isMouseReleased(sf::Event);
	void checkClick();
	bool mouseOnButton(sf::Sprite&);
	void handleClick(sf::Sprite&);
	bool clickOnButton(sf::Sprite&);
};
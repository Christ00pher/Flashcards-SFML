#pragma once
#include "IState.h"
#include "Flashcards.h"

enum Buttons { Start, Handle, Options, Exit};

class StateMenu : public IState
{
private:
	const short TOTAL_BUTTONS;
	sf::Texture t_button[4];
	sf::Sprite button[4];
	sf::Texture t_background;
	sf::Sprite background;
	sf::Vector2f buttonSize;
	void highlightButton(sf::Sprite&, int);
	void undo(sf::Sprite&);
public:
	StateMenu(Flashcards &flashcards);
	~StateMenu() {};
	virtual void update();
	virtual void render();
	virtual void checkButtons();
	void checkClick();
	bool mouseOnButton(sf::Sprite&);
	void handleClick(sf::Sprite&);
};
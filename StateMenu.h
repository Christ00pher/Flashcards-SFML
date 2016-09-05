#pragma once
#include "IState.h"
#include "Flashcards.h"

enum Buttons { Start, Handle, Options, Exit};

class StateMenu : public IState
{
private:
	const short TOTAL_BUTTONS;
	sf::Vector2f buttonSize;
	struct Button
	{
		sf::Texture t_button;
		sf::Sprite button;
		std::string defaultPath;
		std::string markedPath;
	};
	Button button[4];
	void highlightButton(int);
	void undo(int);
public:
	StateMenu(Flashcards &flashcards);
	~StateMenu() {};
	virtual void update();
	virtual void render();
	virtual void checkButtons(sf::Event);
	virtual void pollEvent();
	bool isMouseReleased(sf::Event);
	void checkClick();
	bool mouseOnButton(sf::Sprite&);
	void handleClick(sf::Sprite&);
};
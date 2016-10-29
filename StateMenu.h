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
	sf::String string;
public:
	StateMenu();
	StateMenu(Flashcards &flashcards);
	~StateMenu() {};
	virtual void update();
	virtual void render();
	virtual void checkButtons(sf::Event);
	virtual void pollEvent();
	void handleClickStart();
	void handleClickManage();
	void handleClickOptions();
	void handleClickExit();
};
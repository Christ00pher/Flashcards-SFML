#pragma once
#include "Flashcards.h"
#include "Window.h"
#include <SFML/Graphics.hpp>

class IState
{
protected:
	Flashcards* flashcards;
	Window window;
	bool end;
	bool stateMenu;
	bool stateStart;
	bool stateHandle;
	bool stateOptions;
public:
	IState() {};
	IState(Flashcards &flashcards);
	virtual ~IState() {};
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void pollEvent();
	virtual bool getMenu();
	virtual bool getStart();
	virtual bool getHandle();
	virtual bool getOptions();
	virtual bool toExit();
};
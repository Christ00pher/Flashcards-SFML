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
public:
	IState() {};
	IState(Flashcards &flashcards);
	virtual ~IState() {};
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void pollEvent();
	virtual void checkButtons() = 0;
	bool toExit();
};
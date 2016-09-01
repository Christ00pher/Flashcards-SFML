#pragma once
#include "Flashcards.h"
#include "Window.h"

class IState
{
private:
	Flashcards* p_flashcards;
public:
	IState() {};
	IState(Flashcards &flashcards);
	virtual ~IState() {};
	virtual void update() {};
	virtual void render() {};
	virtual void showVar();
	virtual void setVar(int);
};
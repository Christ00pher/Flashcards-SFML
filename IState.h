#pragma once
#include "Flashcards.h"
#include "Window.h"

class IState
{
private:
	Flashcards flashcards;
public:
	IState() {};
	virtual ~IState() {};
	virtual void update() {};
	virtual void render() {};
	Flashcards & getFlashcards();
};
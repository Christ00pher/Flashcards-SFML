#pragma once
#include "IState.h"
#include "Flashcards.h"

class StateStart : public IState
{
private:
	Flashcards flashcards;
public:
	StateStart();
	~StateStart() {};
};
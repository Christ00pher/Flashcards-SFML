#pragma once
#include "IState.h"
#include "Flashcards.h"

class StateStart : public IState
{
private:
	Flashcards *p_flashcards;
public:
	StateStart(Flashcards &flashcards);
	void showVar();
	~StateStart() {};
	void setVar(int);
};
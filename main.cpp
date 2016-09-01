#include "IState.h"
#include "StateStart.h"
#include <iostream>
#include "Flashcards.h"

int main()
{
	Flashcards flashcards;
	IState *state1 = new IState(flashcards);
	state1->setVar(1);
	state1->showVar();
	state1 = new StateStart(flashcards);
	
	state1->showVar();
	state1->setVar(2);
	state1 = new IState(flashcards);
	state1->showVar();
	state1->setVar(3);
	state1->showVar();
	state1 = new StateStart(flashcards);
	state1->showVar();
	/*
	IState* state = new StateStart();
	while(true)
	{
		state->update();
		state->render();
		 ...
	}
	 * */
	return 0;
}
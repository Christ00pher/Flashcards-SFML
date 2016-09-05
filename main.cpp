#include "IState.h"
#include "StateMenu.h"
#include <iostream>
#include "Flashcards.h"

int main()
{
	Flashcards flashcards;
	
	IState* state = new StateMenu(flashcards);
	
	while(!state->toExit())
	{
		state->update();
		state->render();
	}
	return 0;
}
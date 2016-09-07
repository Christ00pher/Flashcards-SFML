#include "IState.h"
#include "StateMenu.h"
#include <iostream>
#include "Flashcards.h"
#include "StateOptions.h"
#include "Window.h"

int main()
{
	Flashcards flashcards;
	Window window;
	
	IState* state = new StateMenu(flashcards,window);
	
	while(!state->toExit())
	{
		state->update();
		state->render();
		
		if (state->getStateMenu()) 
			state = new StateMenu(flashcards,window);
		
		if (state->getStateOptions())
			state = new StateOptions(flashcards,window);
	}
	return 0;
}
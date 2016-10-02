#include "IState.h"
#include "StateMenu.h"
#include "Flashcards.h"
#include "StateOptions.h"
#include "Window.h"
#include "StateManage.h"

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
		
		else if (state->getStateOptions())
			state = new StateOptions(flashcards,window);
			
		else if (state->getStateHandle())
			state = new StateManage(flashcards,window);
	}
	return 0;
}
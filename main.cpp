#include "IState.h"
#include "StateMenu.h"
#include "Flashcards.h"
#include "StateOptions.h"
#include "Window.h"
#include "StateManage.h"
#include "StateStart.h"

Flashcards flashcards;

int main()
{
	IState* state = new StateMenu(flashcards);
	
	while(!state->toExit())
	{
		state->update();
		state->render();
		
		if (state->getStateMenu()) 
			state = new StateMenu(flashcards);
		
		else if (state->getStateOptions())
			state = new StateOptions(flashcards);
			
		else if (state->getStateManage())
			state = new StateManage(flashcards);
		
		else if (state->getStateStart())
			state = new StateStart(flashcards);
	}
	return 0;
}
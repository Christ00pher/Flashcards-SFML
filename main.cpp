#include "IState.h"
#include "StateMenu.h"
#include "Flashcards.h"
#include "StateOptions.h"
#include "Window.h"
#include "StateManage.h"
#include "StateStart.h"

void changeState(IState *(&state))
{
	if ( state->getStateMenu() ) 
			state = new StateMenu();
	
	else if ( state->getStateOptions() )
		state = new StateOptions();
		
	else if ( state->getStateManage() )
		state = new StateManage();
	
	else if ( state->getStateStart() )
		state = new StateStart();
}

int main()
{
	Sound::instance().playSoundtrack();
	
	IState* state = new StateMenu();
	while(!state->toExit())
	{
		state->update();
		state->render();
		changeState(state);
	}
	return 0;
}
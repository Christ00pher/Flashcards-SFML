#include "IState.h"
#include "StateStart.h"
#include <iostream>
#include "Flashcards.h"

int main()
{
	Flashcards flashcards;
	
	IState* state = new StateStart(flashcards);
	while(!state->toExit())
	{
	state->update();
	state->render();
	
	
	/*
	switch (State)
	{
		case StateHandleFlashcards: state = new StateHandle...();
		case StateOptions: state = new StateOptions();
		
	}
	*/
	}
	return 0;
}
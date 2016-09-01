#include "IState.h"
#include <iostream>

void IState::showVar()
{ 
	std::cout << "IState: ";
	p_flashcards->showVar(); 
}

void IState::setVar(int x)
{
	p_flashcards->setVar(x);
}

IState::IState(Flashcards &flashcards)
{
	this->p_flashcards = &flashcards;
}
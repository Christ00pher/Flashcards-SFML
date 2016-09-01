#include "StateStart.h"
#include <iostream>
StateStart::StateStart(Flashcards &flashcards)
{
	this->p_flashcards = &flashcards;
}

void StateStart::showVar()
{
	std::cout << "StateStart: ";
	p_flashcards->showVar();
}

void StateStart::setVar(int x)
{
	p_flashcards->setVar(x);
}
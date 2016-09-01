#include "Flashcards.h"
#include <iostream>

Flashcards::Flashcards() 
{
}

void Flashcards::setVar(int x) { example = x; }

void Flashcards::showVar()
{
	std::cout << example << std::endl;
}
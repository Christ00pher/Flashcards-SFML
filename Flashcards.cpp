#include "Flashcards.h"

Flashcards::Flashcards()
{
	srand(time(NULL));
	wrong_words.clear();
	correct_words.clear();
	asked_words.clear();
	
}

Flashcards::~Flashcards()
{
	wrong_words.clear();
	correct_words.clear();
	asked_words.clear();
}

void Flashcards::Add()
{
	
}
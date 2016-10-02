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

void Flashcards::add(sf::String polish, sf::String english) 
{
	all_words[english] = polish;
}

void Flashcards::show() {
	for (std::map<std::string, std::string>::iterator it = all_words.begin(); it != all_words.end(); it++)
	{
		std::cout << "English word: " << it->first 
		<< " " << "Polish word: " << it->second << std::endl;
	}
	std::cout << std::endl;
}
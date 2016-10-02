#pragma once
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

class Flashcards
{
private:
    std::map<std::string, std::string> all_words; //contains all words
    std::map<std::string, std::string> correct_words; //contains correct answers
    std::map<std::string, std::string> wrong_words; //contains wrong answers
    std::map<std::string, std::string> asked_words; //contains already asked words
public:
	Flashcards();
	~Flashcards();
	void add(sf::String,sf::String);
	void show();
};
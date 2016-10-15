#pragma once
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "fstream"
#include <SFML/Graphics.hpp>

class Flashcards
{
private:
    std::map<std::string, std::string> all_words; //contains all words
    std::map<std::string, std::string> correct_words; //contains correct answers
    std::map<std::string, std::string> wrong_words; //contains wrong answers
    std::map<std::string, std::string> asked_words; //contains already asked words
	std::string question; //helper variable containing questioned word
	std::string answer; //helper variable conatining user's answer
public:
	Flashcards();
	~Flashcards();
	void add(sf::String,sf::String);
	void show();
	void saveToFile();
	void loadFromFile();
	void ask();
	void handleAnswer(std::string);
	std::pair<std::string, std::string> random();
	void isFull();
	bool checkAsked(std::map<std::string, std::string>::iterator);
	void clearAll();
	void clearHelpers();
	void clear();
	void clearFile();
};
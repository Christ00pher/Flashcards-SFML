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
	std::string answer; //english word
	std::string question; //polish word
public:
	Flashcards();
	~Flashcards();
	std::string getAnswer();
	std::string getQuestion();
	void add(sf::String,sf::String);
	void show();
	void saveToFile();
	void loadFromFile();
	void ask();
	void handleAnswer(std::string);
	void random();
	void isFull();
	bool checkAsked(std::map<std::string, std::string>::iterator);
	void clearAll();
	void clearHelpers();
	void clear();
	void clearFile();
};
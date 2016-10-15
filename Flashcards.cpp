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

void Flashcards::show() 
{
	for (std::map<std::string, std::string>::iterator it = all_words.begin(); it != all_words.end(); it++)
	{
		std::cout << "English word: " << it->first 
		<< " " << "Polish word: " << it->second << std::endl;
	}
	std::cout << std::endl;
}

void Flashcards::saveToFile()
{
    std::ofstream file;
    file.open("flashcards.txt", std::ios::out);

    for (std::map<std::string, std::string>::iterator it = all_words.begin(); it != all_words.end(); it++)
        file << it->first << " " << it->second << std::endl;

    file.close();
}

void Flashcards::ask()
{
    if (!all_words.empty())
    {
        std::string answer;
        std::pair<std::string, std::string> question;
		
        asked_words.clear();
    }
}

void Flashcards::handleAnswer(std::string answer)
{
    /*if (answer == question.second)
	{
		correct_words.insert(question);
		//throw communicate
	}
	
    else
	{
		wrong_words.insert(question);
		//throw communicate
	}*/
}

std::pair<std::string, std::string> Flashcards::random()
{
    int n; //random number
    std::map<std::string, std::string>::iterator it;
    do
    {
        n = rand() % (all_words.size());
        it = all_words.begin();
        for (int i = 0; i < n; i++)
            it++;
    } while (checkAsked(it));

    isFull();

    return *it;
}

void Flashcards::isFull()
{
    if (asked_words.size() == all_words.size())
        asked_words.clear();
}

bool Flashcards::checkAsked(std::map<std::string, std::string>::iterator quest)
{
    std::map<std::string, std::string>::iterator cmp = asked_words.find(quest->first);
    if (cmp == asked_words.end())
    {
        asked_words.insert(*quest);
        return false;
    }
    else
        return true;
}

void Flashcards::clearAll()
{
    wrong_words.clear();
    correct_words.clear();
    all_words.clear();
}

void Flashcards::clearHelpers()
{
    wrong_words.clear();
    correct_words.clear();
}

void Flashcards::clear()
{
	
}

void Flashcards::loadFromFile()
{
    std::ifstream file;
    std::string polish,english; //helper variables to store words from the file
    file.open("flashcards.txt", std::ios::in);
    while (!file.eof())
    {
        polish = english = "";
        file >> polish;
        file >> english;
        if (polish != "" && english != "")
            all_words.insert(std::pair<std::string, std::string>(polish,english));
    }
    file.close();
}

void Flashcards::clearFile()
{
    std::ofstream file;
    file.open("flashcards.txt", std::ios::out);
    file << "";
    file.close();
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Caption.h"
#include "Flashcards.h"

enum keys
{
	esc = 8,
	enter = 13,
	tab = 9
};

class TextBox
{
private:
	sf::RectangleShape textbox;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f size;
	bool marked;
	sf::Vector2f textPosition;
	Caption text;
public:
	TextBox(float x = 100,float y = 100);
	TextBox();
	~TextBox();
	void draw();
	void mark();
	void remark();
	bool isMarked();
	bool isEmpty();
	void clear();
	sf::String& getString();
	void setString(std::string);
	sf::Vector2f getPosition();
	sf::Vector2f getTextPosition();
	sf::Vector2f getSize();
	bool mouseOnTextbox(sf::Vector2i);
	void getInput(sf::Event);
	bool unwantedKeys(sf::Event);
};
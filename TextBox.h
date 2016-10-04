#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class TextBox
{
private:
	sf::RectangleShape textbox;
	sf::Vector2f position;
	sf::Vector2f size;
	Window *window;
	bool marked;
	sf::Vector2f textPosition;
public:
	TextBox(Window&,float x = 100,float y = 100);
	TextBox();
	~TextBox();
	void draw();
	void mark();
	void remark();
	bool isMarked();
	sf::Vector2f getPosition();
	sf::Vector2f getTextPosition();
	sf::Vector2f getSize();
};
#include "TextBox.h"
#include <iostream>

TextBox::TextBox() {}

TextBox::TextBox(Window &p_window, float x, float y)
{
	window = &p_window;
	position = {x, y};
	textPosition.x = x+3;
	textPosition.y = y-3;
	size = {300, 30};
	textbox.setFillColor(sf::Color::White);
	textbox.setOutlineColor(sf::Color::Black);
	textbox.setOutlineThickness(2);
	textbox.setSize(size);
	textbox.setOrigin(size.x/2, size.y/2);
	textbox.setPosition(position);
	marked = false;
	std::cout << "Position x: " << position.x << std::endl;
	std::cout << "Position y: " << position.y << std::endl;
}

TextBox::~TextBox() {}

void TextBox::draw()
{
	window->draw(textbox);
}

sf::Vector2f TextBox::getPosition()
{
	return position;
}

sf::Vector2f TextBox::getSize()
{
	return size;
}

void TextBox::mark()
{
	textbox.setFillColor(sf::Color::Yellow);
	marked = true;
}

void TextBox::remark()
{
	textbox.setFillColor(sf::Color::White);
	marked = false;
}

bool TextBox::isMarked()
{
	return marked;
}

sf::Vector2f TextBox::getTextPosition()
{
	return textPosition;
}
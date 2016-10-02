#include "TextBox.h"

TextBox::TextBox() {}

TextBox::TextBox(Window &p_window, float x, float y)
{
	window = &p_window;
	position = {x, y};
	size = {300, 30};
	textbox.setFillColor(sf::Color::White);
	textbox.setOutlineColor(sf::Color::Black);
	textbox.setOutlineThickness(2);
	textbox.setSize(size);
	textbox.setPosition(position);
	Marked = false;
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
	Marked = true;
}

void TextBox::remark()
{
	textbox.setFillColor(sf::Color::White);
	Marked = false;
}

bool TextBox::isMarked()
{
	return Marked;
}
#include "Caption.h"

Caption::Caption()
:size(30),
 position(0,0),
 fontPath("data/StateOptions/Capture_it.ttf"),
 string("Caption"),
 color(sf::Color::Black)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setColor(color);
	text.setString(string);
	
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
					textRect.top  + textRect.height/2.0f);
}

Caption::~Caption() {}

Caption::Caption(std::string string, float x, float y, std::string fontPath)
:color(sf::Color::Black),
 size(30)
{
	this->string = string;
	position = {x,y};
	this->fontPath = fontPath;
	
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setColor(color);
	text.setString(string);
	text.setPosition(position);
}

sf::Text& Caption::getText() { return text; }

void Caption::setPosition(float x, float y)
{
	position = {x,y};
	text.setPosition(position);
}

void Caption::setSize(int size) 
{
	this->size = size;
	text.setCharacterSize(size);
}

void Caption::setColor(sf::Color color)
{
	this->color = color;
	text.setColor(color);
}

void Caption::setFont(std::string fontPath)
{
	this->fontPath = fontPath;
	font.loadFromFile(fontPath);
	text.setFont(font);
}

void Caption::setText(std::string string)
{
	this->string = string;
	text.setString(string);
}
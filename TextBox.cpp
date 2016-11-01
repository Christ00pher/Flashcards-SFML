#include "TextBox.h"
#include <iostream>

TextBox::TextBox() {}

TextBox::TextBox(float x, float y)
:text("", x, y)
{
	texture.loadFromFile("data/General/fl6.png");
	size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 2,size.y / 2);
	sprite.setScale(0.5,0.5);
	size.x = size.x * 0.5;
	size.y = size.y * 0.5;
	position = {x, y};
	sprite.setPosition(position);
	
	cornerPos = { position.x - size.x / 2, position.y - size.y / 2 };
	
	marked = false;
}

TextBox::~TextBox() {}

void TextBox::draw()
{
	Window::instance().draw(sprite);
	Window::instance().draw(text.getText());
}

sf::Vector2f TextBox::getPosition()
{
	return position;
}

sf::Vector2u TextBox::getSize()
{
	return size;
}

void TextBox::mark()
{
	marked = true;
}

void TextBox::remark()
{
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

bool TextBox::mouseOnTextbox(sf::Vector2i mousePos)
{
	if (mousePos.x >= cornerPos.x &&
		mousePos.x <= cornerPos.x + size.x &&
		mousePos.y >= cornerPos.y &&
		mousePos.y <= cornerPos.y + size.y)
		{
			return true;
		}
	
	return false;
}

void TextBox::getInput(sf::Event event)
{
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode < 128)
		{
			if (!unwantedKeys(event))
				text.add(event);
			
			if (event.text.unicode == esc && !isEmpty())
				text.getString().erase(text.getString().getSize() - 1);
		}
		
		text.setString(getString());
		
		if ( text.getTextSize().x >= size.x )
		{
			std::cout << "Too much letters" << std::endl;
			//wrap();
		}
	}
}

void TextBox::setString(std::string string)
{
	text.setString(string);
}

void TextBox::clear()
{
	text.clear();
}

bool TextBox::isEmpty()
{
	return text.isEmpty();
}

sf::String& TextBox::getString()
{
	return text.getString();
}

bool TextBox::unwantedKeys(sf::Event event)
{
	if (event.text.unicode == esc ||
		event.text.unicode == enter ||
		event.text.unicode == tab)
			return true;
	
	return false;
}

void TextBox::wrap()
{
	text.add(13);
}
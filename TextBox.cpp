#include "TextBox.h"

TextBox::TextBox() {}

TextBox::TextBox(float x, float y)
:text("", x, y)
{
	position = {x, y};
	texture.loadFromFile("data/General/fl6.png");
	size = texture.getSize();
	sprite.setTexture(texture);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setScale(0.5,0.5);
	sprite.setOrigin(size.x / 2,size.y / 2);
	sprite.setPosition(position);
	
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
	int x = position.x - 150;
	int y = position.y - 15;
	
	if (mousePos.x >= x
		&& mousePos.x <= x + 300
		&& mousePos.y >= y 
		&& mousePos.y <= y + 30)
		return true;
	
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
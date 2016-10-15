#include "TextBox.h"

TextBox::TextBox() {}

TextBox::TextBox(Window &p_window, float x, float y)
:text("", x, y)
{
	window = &p_window;
	
	position = {x, y};
	size = {300, 30};
	
	textbox.setFillColor(sf::Color::White);
	textbox.setOutlineColor(sf::Color::Black);
	textbox.setOutlineThickness(2);
	textbox.setSize(size);
	textbox.setOrigin(size.x/2, size.y/2);
	textbox.setPosition(position);
	
	marked = false;
}

TextBox::~TextBox() {}

void TextBox::draw()
{
	window->draw(textbox);
	window->draw(text.getText());
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
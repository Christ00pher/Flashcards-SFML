#include "Button.h"

Button::Button() {}


Button::Button(std::string def, std::string mark, sf::Vector2f pos)
:position(pos),
 defaultPath(def),
 markedPath(mark)
{
	defaultTexture.loadFromFile(defaultPath);
	markedTexture.loadFromFile(markedPath);
	sprite.setTexture(defaultTexture);
	
	size = defaultTexture.getSize();
	
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(position);
	
	marked = false;
	leftClick = false;
	activated = false;
	
	corner.x = position.x - size.x / 2;
	corner.y = position.y - size.y / 2;
}

Button::~Button() {}

void Button::mark()
{
	sprite.setTexture(markedTexture);
}

void Button::remark()
{
	sprite.setTexture(defaultTexture);
}

sf::Sprite& Button::getSprite()
{
	return sprite;
}

void Button::checkCollision(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonReleased)
		leftClick = false;
		
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !leftClick)
	{
		leftClickPos = sf::Mouse::getPosition( *(Window::instance().getWindow()) );
		leftClick = true;
	}
		
	sf::Vector2i mousePos = sf::Mouse::getPosition( *(Window::instance().getWindow()) );
	
	if (mousePos.x >= corner.x && mousePos.x <= corner.x + size.x &&
		mousePos.y >= corner.y && mousePos.y <= corner.y + size.y)
		{
			if (marked)
			{
				remark();
				marked = false;
			}
		}
	
	else
	{
		mark();
		marked = true;
	}
}

void Button::setDefaultPath(std::string def)
{
	defaultPath = def;
}

void Button::setMarkedPath(std::string marked)
{
	markedPath = marked;
}

void Button::draw()
{
	Window::instance().draw(sprite);
}

bool Button::isMouseReleased(sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left &&
		event.type == sf::Event::MouseButtonReleased)
			return true;
	
	return false;
}

bool Button::clickOnButton()
{
	if (leftClickPos.x >= corner.x && leftClickPos.x <= corner.x + size.x
		&& leftClickPos.y >= corner.y && leftClickPos.y <= corner.y + size.y)
			return true;
			
	return false;
}
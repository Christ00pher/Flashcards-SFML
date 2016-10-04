#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Caption
{
private:
	sf::Font font;
	sf::Text text;
	sf::String string;
	sf::Vector2f position;
	int size;
	std::string fontPath;
	sf::Color color;
public:
	Caption();
	~Caption();
	Caption(std::string,float = 0,float = 0,std::string s = "data/StateOptions/Capture_it.ttf");
	sf::Text& getText();
	void setPosition(float,float);
	void setSize(int);
	void setColor(sf::Color);
	void setFont(std::string);
	void setText(std::string);
};
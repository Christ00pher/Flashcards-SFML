#pragma once
#include <SFML/Graphics.hpp>

class Window
{
private:
	sf::RenderWindow window;
	sf::Vector2f size;
public:
	Window() {};
	~Window() {};
};
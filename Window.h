#pragma once

#include <SFML/Graphics.hpp>

class Window
{
private:
	sf::RenderWindow window;
	int x;
	int y;
public:
	Window();
	~Window();
	sf::RenderWindow* getWindow();
	void closeWindow();
	void startRender();
	void finishRender();
	void draw(sf::Drawable&);
	int getX();
	int getY();
};
#pragma once
#include <SFML/Graphics.hpp>

class Window
{
private:
	sf::RenderWindow window;
public:
	Window();
	~Window();
	sf::RenderWindow* getWindow();
	void closeWindow();
	void startRender();
	void finishRender();
	void draw(sf::Drawable&);
};
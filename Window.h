#pragma once
#include <SFML/Graphics.hpp>

//Singleton class

class Window
{
private:
	Window();
	
	sf::RenderWindow window;
	float x;
	float y;
public:
	static Window & instance()
	{
		static Window a;
		return a;
	}
	
	~Window();
	sf::RenderWindow* getWindow();
	void closeWindow();
	void startRender();
	void finishRender();
	void draw(sf::Drawable&);
	float getX();
	float getY();
};
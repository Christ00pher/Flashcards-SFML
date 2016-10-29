#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Button
{
protected:
	sf::Texture defaultTexture;
	sf::Texture markedTexture;
	sf::Sprite sprite;
	std::string defaultPath;
	std::string markedPath;
	bool marked;
	sf::Vector2f position; //origin
	sf::Vector2f corner; //position of up-left corner
	sf::Vector2u size;
	sf::Vector2i leftClickPos;
	bool leftClick;
	
public:
	Button();
	Button(std::string, std::string, sf::Vector2f pos = {0,0});
	~Button();
	void setDefaultPath(std::string);
	void setMarkedPath(std::string);
	bool isMouseReleased(sf::Event);
	bool clickOnButton();
	void checkCollision(sf::Event);
	void draw();
	void mark();
	void remark();
	sf::Sprite& getSprite();
};
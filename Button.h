#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Caption.h"

class Button
{
protected:
	sf::Texture defaultTexture;
	sf::Texture markedTexture;
	sf::Sprite sprite;
	std::string defaultPath;
	std::string markedPath;
	Caption caption;
	bool marked;
	sf::Vector2f position; //origin
	sf::Vector2f corner; //position of up-left corner
	sf::Vector2u size;
	sf::Vector2i leftClickPos;
	bool leftClick;
	bool activated;
	
public:
	Button();
	Button(std::string, std::string, sf::Vector2f pos = {0,0}, std::string text = "");
	~Button();
	void setDefaultPath(std::string);
	void setPosition(sf::Vector2f);
	void setPosition(float,float);
	void setMarkedPath(std::string);
	bool isMarked();
	bool isMouseReleased(sf::Event);
	bool clickOnButton();
	void checkCollision(sf::Event);
	void getInput(sf::Event);
	void draw();
	void mark();
	void remark();
	sf::Vector2u getSize();
	sf::Sprite& getSprite();
};
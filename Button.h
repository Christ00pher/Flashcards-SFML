#pragma once
#include <SFML/Graphics.hpp>

class Button
{
protected:
	sf::Texture defaultTexture;
	sf::Texture markedTexture;
	sf::Sprite sprite;
	std::string defaultPath;
	std::string markedPath;
	bool marked;
	sf::Vector2f position;
	sf::Vector2u size;
	
public:
	Button();
	Button(std::string, std::string, sf::Vector2f pos = {0,0});
	~Button();
	void setDefaultPath(std::string);
	void setMarkedPath(std::string);
	void checkCollision(sf::Event, sf::RenderWindow&);
	void draw(sf::RenderWindow&);
	void mark();
	void remark();
	sf::Sprite& getSprite();
};
#pragma once
#include "Flashcards.h"
#include "Window.h"
#include <SFML/Graphics.hpp>

class IState
{
protected:
	Flashcards* flashcards;
	Window* window;
	bool end;
	bool stateMenu;
	bool stateStart;
	bool stateHandle;
	bool stateOptions;
	sf::Texture t_background;
	sf::Sprite background;
	struct Button
	{
		sf::Texture t_button;
		sf::Sprite button;
		std::string defaultPath;
		std::string markedPath;
	};
public:
	IState();
	virtual ~IState() {};
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void pollEvent();
	bool toReturn(sf::Event);
	bool toExit();
	bool getStateMenu();
	bool getStateHandle();
	bool getStateOptions();
	bool getStateStart();
	bool isActive();
};
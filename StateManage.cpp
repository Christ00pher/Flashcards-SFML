#include "StateManage.h"
#include <iostream>

StateManage::StateManage(Flashcards& flashcards, Window& window)
:tbEnglish(window,window.getX() / 4, 50),
 tbPolish(window,3 * window.getX() / 4, 50)
{
	this->window = &window;
	this->flashcards = &flashcards;
	font.loadFromFile("data/StateOptions/Capture_it.ttf");
	t_polish.setFont(font);
	t_polish.setCharacterSize(30);
	t_polish.setColor(sf::Color::Black);
	t_polish.setPosition(tbPolish.getTextPosition());
	
	t_english.setFont(font);
	t_english.setCharacterSize(30);
	t_english.setColor(sf::Color::Black);
	t_english.setPosition(tbEnglish.getTextPosition());
}

StateManage::~StateManage() {}

void StateManage::update()
{
	pollEvent();
}

void StateManage::render()
{
	window->startRender();
	window->draw(background);
	tbEnglish.draw();
	tbPolish.draw();
	window->draw(t_polish);
	window->draw(t_english);
	window->finishRender();
}

void StateManage::pollEvent()
{
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		toReturn(event);
		
		mark(event);
		
		handleInput(event);
	}
}

void StateManage::toReturn(sf::Event event)
{
	if (event.type == sf::Event::Closed)
			window->closeWindow();
			
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			stateMenu = true;
	}
}

void StateManage::mark(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition( *(window->getWindow()) );
			
			if (mousePos.x >= tbEnglish.getPosition().x 
				&& mousePos.x <= tbEnglish.getPosition().x + 300
				&& mousePos.y >= tbEnglish.getPosition().y 
				&& mousePos.y <= tbEnglish.getPosition().y + 30)
				{
					std::cout << "Position in func x: " << tbEnglish.getPosition().x << std::endl;
					std::cout << "Position in func y: " << tbEnglish.getPosition().y << std::endl;
					tbEnglish.mark();
					tbPolish.remark();
				}
			
			else if (mousePos.x >= tbPolish.getPosition().x 
				&& mousePos.x <= tbPolish.getPosition().x + 300
				&& mousePos.y >= tbPolish.getPosition().y 
				&& mousePos.y <= tbPolish.getPosition().y + 30)
				{
					tbPolish.mark();
					tbEnglish.remark();
				}
					
			else
			{
				tbPolish.remark();
				tbEnglish.remark();
				polish.clear();
				english.clear();
				t_polish.setString(polish);
				t_english.setString(english);
			}
		}
	}
}

void StateManage::handleInput(sf::Event event)
{
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode < 128 && tbPolish.isMarked())
		{
			if (event.text.unicode == 13)
			{
				if (!polish.isEmpty() && !english.isEmpty())
				{
					flashcards->add(polish,english);
					flashcards->show();
					polish.clear();
					english.clear();
				}
			}
			
			if (event.text.unicode == 9)
			{
				tbEnglish.mark();
				tbPolish.remark();
				return;
			}
			
			if (polish.isEmpty())
			{
				if (event.text.unicode != 8 && event.text.unicode != 13)
					polish += event.text.unicode;
			}
			
			else 
			{
				if (event.text.unicode == 8 && !polish.isEmpty())
				{
					polish.erase(polish.getSize() - 1);
				}
				else
					polish += event.text.unicode;
			}
			
		}
		
		else if (event.text.unicode < 128 && tbEnglish.isMarked())
		{
			if (event.text.unicode == 13)
			{
				tbPolish.mark();
				tbEnglish.remark();
				return;
			}
			
			if (event.text.unicode == 9)
			{
				tbPolish.mark();
				tbEnglish.remark();
				return;
			}
			
			if (english.isEmpty())
			{
				if (event.text.unicode != 8)
					english += event.text.unicode;
			}
			else 
			{
				if (event.text.unicode == 8 && !english.isEmpty())
				{
					english.erase(english.getSize() - 1);
				}
				else
					english += event.text.unicode;
			}
		}
		
		t_polish.setString(polish);
		t_english.setString(english);
	}
}
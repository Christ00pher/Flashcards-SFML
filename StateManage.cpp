#include "StateManage.h"

StateManage::StateManage(Flashcards& flashcards, Window& window)
:tbEnglish(window,100,100),
 tbPolish(window,450,100)
{
	this->window = &window;
	this->flashcards = &flashcards;
	font.loadFromFile("data/StateOptions/Capture_it.ttf");
	t_polish.setFont(font);
	t_polish.setCharacterSize(30);
	t_polish.setColor(sf::Color::Black);
	t_polish.setPosition(tbPolish.getPosition().x + 3, tbPolish.getPosition().y - 3);
}

StateManage::~StateManage() {}

void StateManage::pollEvent()
{
	sf::Vector2i mousePos;
	sf::Event event;
	while (window->getWindow()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->closeWindow();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				stateMenu = true;
		}
		
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mousePos = sf::Mouse::getPosition( *(window->getWindow()) );
				
				if (mousePos.x >= tbEnglish.getPosition().x 
					&& mousePos.x <= tbEnglish.getPosition().x + 300
					&& mousePos.y >= tbEnglish.getPosition().y 
					&& mousePos.y <= tbEnglish.getPosition().y + 30)
					{
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
					t_polish.setString(polish);
				}
			}
		}
		
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode == 13)
			{
				flashcards->add(polish);
				//flashcards->show();
				polish.clear();
			}
			
			
			else if (event.text.unicode < 128 && tbPolish.isMarked())
			{
				if (polish.isEmpty())
				{
					if (event.text.unicode != 8)
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
			t_polish.setString(polish);
		}
	}
}

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
	window->finishRender();
}
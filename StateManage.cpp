#include "StateManage.h"

StateManage::StateManage(Flashcards& flashcards, Window& window)
:tbEnglish(window,window.getX() / 4, 50),
 tbPolish(window,3 * window.getX() / 4, 50),
 c1("English word", window.getX() / 4, 20),
 c2("Polish word", 3 * window.getX() / 4, 20)
{
	this->window = &window;
	this->flashcards = &flashcards;
	c1.setSize(25);
	c2.setSize(25);
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
	
	window->draw( c2.getText() );
	window->draw( c1.getText() );
	window->finishRender();
}

void StateManage::pollEvent()
{
	sf::Event event;
	while ( window->getWindow()->pollEvent(event) )
	{
		if ( toReturn(event) )
			break;
		
		mark(event);
		
		handleInput(event);
	}
}

bool StateManage::toReturn(sf::Event event)
{
	if (event.type == sf::Event::Closed)
			window->closeWindow();
			
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			stateMenu = true;
	}
	
	return stateMenu;
}

void StateManage::mark(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			//getting up-left corner of textbox
			sf::Vector2i mousePos = sf::Mouse::getPosition( *(window->getWindow()) );
			
			if (tbEnglish.mouseOnTextbox(mousePos))
			{
				tbEnglish.mark();
				tbPolish.remark();
			}
			
			else if (tbPolish.mouseOnTextbox(mousePos))
			{
				tbPolish.mark();
				tbEnglish.remark();
			}
			
			else
			{
				tbPolish.remark();
				tbEnglish.remark();
			}
		}
	}
}

void StateManage::handleInput(sf::Event event)
{
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode < 128)
		{
			if (event.text.unicode == tab)
				remark();
			
			if (event.text.unicode == enter)
			{
				if ( isCorrect() )
				{
					flashcards->add( tbPolish.getString(), tbEnglish.getString() );
					tbPolish.clear();
					tbEnglish.clear();
				}
			}
			
			if (tbPolish.isMarked())
			{
				tbPolish.getInput(event);
			}
			
			if (tbEnglish.isMarked())
			{
				tbEnglish.getInput(event);
			}
		}
	}
}

void StateManage::remark()
{
	if (tbPolish.isMarked())
	{
		tbPolish.remark();
		tbEnglish.mark();
	}
	
	else if (tbEnglish.isMarked())
	{
		tbEnglish.remark();
		tbPolish.mark();
	}
}

bool StateManage::isCorrect()
{
	if (tbEnglish.getString() != "" && tbPolish.getString() != "")
		return true;
		
	return false;
}
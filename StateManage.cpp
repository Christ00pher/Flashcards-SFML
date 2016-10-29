#include "StateManage.h"

StateManage::StateManage()
:tbEnglish(Window::instance().getX() / 4, 50),
 tbPolish(3 * Window::instance().getX() / 4, 50),
 c1("English word", Window::instance().getX() / 4, 20),
 c2("Polish word", 3 * Window::instance().getX() / 4, 20)
{
	c1.setSize(30);
	c2.setSize(30);
	click = false;
	tbEnglish.mark();
}

StateManage::~StateManage() {}

void StateManage::update()
{
	pollEvent();
}

void StateManage::render()
{
	Window::instance().startRender();
	Window::instance().draw(background);
	tbEnglish.draw();
	tbPolish.draw();
	
	Window::instance().draw( c2.getText() );
	Window::instance().draw( c1.getText() );
	Window::instance().finishRender();
}

void StateManage::pollEvent()
{
	sf::Event event;
	while ( Window::instance().getWindow()->pollEvent(event) )
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
			Window::instance().closeWindow();
			
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
			sf::Vector2i mousePos = sf::Mouse::getPosition( *(Window::instance().getWindow()) );
			
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
			
			else if (click &&
					!tbPolish.mouseOnTextbox(mousePos) &&
					!tbEnglish.mouseOnTextbox(mousePos))
			{
				tbPolish.remark();
				tbEnglish.remark();
			}
			click = true;
		}
	}
}

void StateManage::handleInput(sf::Event event)
{
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode < 128)
		{
			if (event.text.unicode == enter)
			{
				if ( isCorrect() )
				{
					Flashcards::instance().add( tbPolish.getString(), tbEnglish.getString() );
					tbPolish.clear();
					tbEnglish.clear();
					remark();
					return;
				}
			}
			
			if (event.text.unicode == tab || event.text.unicode == enter)
				remark();
			
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
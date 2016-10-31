#include "StateMenu.h"
StateMenu::StateMenu()
:TOTAL_BUTTONS(4),
 start("data/General/button.png", "data/General/button.png",{250,100}, "Start"),
 manage("data/General/button.png", "data/General/button.png",{250,2*100}, "Manage"),
 options("data/General/button.png", "data/General/button.png",{250,3*100}, "Options"),
 exit("data/General/button.png", "data/General/button.png",{250,4*100}, "Exit"),
 speaker("data/General/speakerOn.png", "data/General/speakerOff.png",{730,70})
{
	//wider buttons
	end = false;
	
	if (!Sound::instance().isPlaying())
		speaker.mark();
}

void StateMenu::update()
{
	pollEvent();
}

void StateMenu::render()
{
	Window::instance().startRender();
	Window::instance().draw(background);
	
	start.draw();
	manage.draw();
	options.draw();
	exit.draw();
	speaker.draw();
	
	Window::instance().finishRender();
}

void StateMenu::pollEvent()
{
	sf::Event event;
	while (Window::instance().getWindow()->pollEvent(event))
	{
		checkButtons(event);
		
		if (event.type == sf::Event::Closed)
		{
			Window::instance().closeWindow();
			end = true;
		}
	}
}

//function checks if the button has to be highlighted, handled or extinguished
void StateMenu::checkButtons(sf::Event event)
{
	start.checkCollision( event );
	manage.checkCollision( event );
	options.checkCollision( event );
	exit.checkCollision( event );
	
	speaker.getInput( event );
	
	if (start.clickOnButton())
		handleClickStart();
		
	if (manage.clickOnButton())
		handleClickManage();
		
	if (options.clickOnButton())
		handleClickOptions();
		
	if (exit.clickOnButton())
		handleClickExit();
		
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (speaker.clickOnButton())
			handleClickSpeaker();
	}
}

//functions checks if changing state is needed or if the app has to be closed
void StateMenu::handleClickExit()
{
	Sound::instance().playButtonSound();
	Window::instance().closeWindow();
	end = true;
}

void StateMenu::handleClickStart()
{
	Sound::instance().playButtonSound();
	stateStart = true;
}

void StateMenu::handleClickManage()
{
	Sound::instance().playButtonSound();
	stateManage = true;
}

void StateMenu::handleClickOptions()
{
	Sound::instance().playButtonSound();
	stateOptions = true;
}

void StateMenu::handleClickSpeaker()
{
	Sound::instance().playButtonSound();
	if ( !speaker.isMarked() )
	{
		Sound::instance().muteSoundtrack();
		speaker.mark();
	}
	
	else
	{
		Sound::instance().playSoundtrack();
		speaker.remark();
	}
}
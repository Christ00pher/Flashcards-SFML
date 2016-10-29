#include "StateMenu.h"
StateMenu::StateMenu()
:TOTAL_BUTTONS(4),
 start("data/StateStart/startDefault.png", "data/StateStart/startMarked.png",{400,80}),
 manage("data/StateStart/handleDefault.png", "data/StateStart/handleMarked.png",{400,2*80}),
 options("data/StateStart/optionsDefault.png", "data/StateStart/optionsMarked.png",{400,3*80}),
 exit("data/StateStart/exitDefault.png", "data/StateStart/exitMarked.png",{400,4*80}),
 speaker("data/General/speakerOn.png", "data/General/speakerOff.png",{730,70})
{
	end = false;
}

void StateMenu::update()
{
	pollEvent();
}

void StateMenu::render()
{
	Window::instance().startRender();
	Window::instance().draw(background);
	
	Window::instance().draw(start.getSprite());
	Window::instance().draw(manage.getSprite());
	Window::instance().draw(options.getSprite());
	Window::instance().draw(exit.getSprite());
	Window::instance().draw(speaker.getSprite());
	
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
		Sound::instance().pauseSoundtrack();
		speaker.mark();
	}
	
	else
	{
		Sound::instance().playSoundtrack();
		speaker.remark();
	}
}
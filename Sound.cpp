#include "Sound.h"
#include <iostream>

Sound::Sound()
{
	soundtrackPath = "data/Sound/soundtrack.wav";
	soundPath = "data/Sound/buttonClick.wav";
	
	if (!soundtrack.openFromFile(soundtrackPath))
		std::cout << "Couldn't open soundtrack file!" << std::endl;
		
	soundtrack.setLoop(true);
	
	buffer.loadFromFile(soundPath);
	sound.setBuffer(buffer);
	sound.setLoop(false);
	
	soundtrack.play();
	
	std::cout << "Sound initialized" << std::endl;
}

void Sound::playButtonSound()
{
	sound.play();
}

void Sound::stopButtonSound()
{
	sound.stop();
}

void Sound::playSoundtrack()
{
	soundtrack.play();
}

void Sound::pauseSoundtrack()
{
	soundtrack.pause();
}

void Sound::stopSoundtrack()
{
	soundtrack.stop();
}
#include "Sound.h"
#include <iostream>

Sound::Sound()
{
	soundtrackPath = "data/Sound/soundtrack2.wav";
	soundPath = "data/Sound/buttonClick.wav";
	
	soundtrackVol = 10;
	soundVol = 15;
	
	if ( !soundtrack.openFromFile(soundtrackPath) )
		std::cout << "Couldn't open soundtrack file!" << std::endl;
		
	soundtrack.setLoop(true);
	soundtrack.setVolume(soundtrackVol);
	
	if ( !buffer.loadFromFile(soundPath) )
		std::cout << "Couldn't open sound file!" << std::endl;
		
	sound.setBuffer(buffer);
	sound.setLoop(false);
	sound.setVolume(soundVol);
	
	playing = false;
	
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
	if (soundtrack.getVolume() == 0)
		soundtrack.setVolume(soundtrackVol);
	
	else
		soundtrack.play();
		
	playing = true;
}

void Sound::pauseSoundtrack()
{
	soundtrack.pause();
	playing = false;
}

void Sound::stopSoundtrack()
{
	soundtrack.stop();
	playing = false;
}

bool Sound::isPlaying()
{
	return playing;
}

void Sound::muteSoundtrack()
{
	soundtrack.setVolume(0);
	playing = false;
}
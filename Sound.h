#pragma once
#include <SFML/Audio.hpp>

class Sound
{
private:
	sf::Sound sound;
	sf::SoundBuffer buffer;
	sf::Music soundtrack;
	
	std::string soundtrackPath;
	std::string soundPath;
	bool playing; //true if the sound is playing ( or volume level > 0 )
	int soundtrackVol; //soundtrack volume level
	int soundVol; //sound volume level
	
	Sound();
public:
	static Sound & instance()
	{
		static Sound a;
		return a;
	}
	
	~Sound() {};
	void playButtonSound();
	void stopButtonSound();
	void playSoundtrack();
	void pauseSoundtrack();
	void stopSoundtrack();
	void muteSoundtrack();
	bool isPlaying();
};
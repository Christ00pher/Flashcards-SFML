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
	
	Sound();
public:
	static Sound & instance()
	{
		static Sound a;
		return a;
	}
	
	~Sound() {};
	void startButtonSound();
	void stopButtonSound();
	void startSoundtrack();
	void pauseSoundtrack();
	void stopSoundtrack();
};
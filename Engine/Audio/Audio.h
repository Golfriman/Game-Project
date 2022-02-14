#pragma once
#include<SFML/Audio.hpp>
#include<map>
class Audio
{
	int backgroundVolume;
	int effectVolume;
	int dialogVolume;
	std::map<sf::String, sf::SoundBuffer> effects;
	std::map<sf::String, sf::SoundBuffer> dialog;
	sf::Music background;

	//key = name music, value = path music
	std::map<sf::String, sf::String> backgroundPath;

	sf::SoundBuffer& loadSound(sf::String path);
public:
	Audio();
	Audio(const Audio& copySource) = delete;
	Audio& operator=(const Audio& copySource) = delete;
	void left(int& volume);
	void right(int& volume);
	int& getBackgroundVolume();
	int& getEffectVolume();
	int& getDialogVolume();
	void playBackgroundMusic(sf::String path);
	void setBackgroundVolume();
	sf::String getBackgroundPath(sf::String name);
	sf::SoundBuffer& getEffects(sf::String name);
	sf::SoundBuffer& getDialog(sf::String name);
	~Audio();
};
#include"Audio.h"

sf::SoundBuffer& Audio::loadSound(sf::String path)
{
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile(path))
	{
		/**/
	}
	return buffer;
}

Audio::Audio()
{
	backgroundVolume = 50;
	effectVolume = 50;
	dialogVolume = 0;
	sf::SoundBuffer sound;
	sound.loadFromFile("resources\\Audio\\effects\\button-28.wav");
	backgroundPath.insert(std::make_pair("Crushed Dreams", "resources\\Audio\\background\\crushed-dreams.wav"));
	effects.insert(std::make_pair("Click", sound));
}

void Audio::left(int& volume)
{
	volume = volume - 10 <= 0 ? 0 : volume - 10;
}

void Audio::right(int& volume)
{
	volume = volume + 10 >= 100 ? 100 : volume + 10;
}

int& Audio::getBackgroundVolume()
{
	return backgroundVolume;
}

int& Audio::getEffectVolume()
{
	return effectVolume;
}

int& Audio::getDialogVolume()
{
	return dialogVolume;
}

void Audio::playBackgroundMusic(sf::String path)
{
	background.openFromFile(path);
	background.play();
	background.setVolume(backgroundVolume);
}

void Audio::setBackgroundVolume()
{
	background.setVolume(backgroundVolume);
}

sf::String Audio::getBackgroundPath(sf::String name)
{
	return backgroundPath[name];
}

sf::SoundBuffer& Audio::getEffects(sf::String name)
{
	return effects[name];
}

sf::SoundBuffer& Audio::getDialog(sf::String name)
{
	return dialog[name];
}

Audio::~Audio()
{

}
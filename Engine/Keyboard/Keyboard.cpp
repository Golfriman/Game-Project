#include "Keyboard.h"

Keyboard::Keyboard()
{
	config.emplace("I", sf::Keyboard::I);
	config.emplace("H", sf::Keyboard::H);
	config.emplace("Escape", sf::Keyboard::Escape);
}

sf::Keyboard::Key& Keyboard::getConfig(std::string name)
{
	if (config[name])
	{
		return config[name];
	}
}

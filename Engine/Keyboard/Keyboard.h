#pragma once
#include <SFML/Graphics.hpp>
#include<unordered_map>
#include<string>
class Keyboard
{
	std::unordered_map<std::string, sf::Keyboard::Key> config;	
public:
	Keyboard();
	sf::Keyboard::Key& getConfig(std::string name);
};
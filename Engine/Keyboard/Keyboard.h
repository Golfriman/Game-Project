#pragma once
#include <SFML/Graphics.hpp>
#include<unordered_map>
#include<string>
class Keyboard
{
	std::unordered_map<std::string, sf::Keyboard::Key> config;
	//struct Key
	//{
	//	Key() = default;
	//	sf::Keyboard::Key left;
	//	sf::Keyboard::Key right;
	//	sf::Keyboard::Key down;
	//	sf::Keyboard::Key up;
	//	sf::Keyboard::Key inventory;
	//	sf::Keyboard::Key hide;
	//	sf::Keyboard::Key accept;
	//	sf::Keyboard::Key escape;
	//}key;
	
public:
	Keyboard();
	sf::Keyboard::Key& getConfig(std::string name);

	/*Key& changeKey(sf::Keyboard::Key& externalKey);*/
};
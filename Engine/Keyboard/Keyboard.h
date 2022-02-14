#pragma once
#include <SFML/Graphics.hpp>
#include<unordered_map>
class Keyboard
{
	struct Key
	{
		Key() = default;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key down;
		sf::Keyboard::Key up;
		sf::Keyboard::Key inventory;
		sf::Keyboard::Key hide;
		sf::Keyboard::Key accept;
		sf::Keyboard::Key escape;
	}key;
	
public:
	Keyboard();
	Key& getConfig();

	/*Key& changeKey(sf::Keyboard::Key& externalKey);*/
};
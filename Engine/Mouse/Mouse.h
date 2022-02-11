#pragma once
#include<SFML/Graphics.hpp>

class Mouse
{
	sf::Mouse* mouse;
	sf::RenderWindow* window;
public:
	Mouse(sf::RenderWindow* window);
	sf::Vector2f getCoordinate();
	sf::Mouse* getMouse();
	~Mouse();
};
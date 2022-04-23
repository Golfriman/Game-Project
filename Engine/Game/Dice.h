#pragma once

#include<SFML/Graphics.hpp>
#include<random>

class Dice: public sf::Drawable
{
	static constexpr size_t maxSprite = 180;
	std::mt19937 *mersenne;
	std::uniform_int_distribution<int> *random;
	std::vector<sf::Texture*> resultRoll;
	sf::RectangleShape dice[2];
	size_t countSprite;
	int firstDice;
	int secondDice;
	sf::Clock localTIME;
	bool finish;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Dice(float x, float y);

	bool rollEnd();

	void roll();
	sf::Vector2u valueRoll();
	~Dice();
};

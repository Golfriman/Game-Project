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
	int& level;
	const sf::Color state[3] = {sf::Color(0x8A, 0x48, 0xA5), sf::Color(0xC2, 0xBC, 0x2A), sf::Color(0xE0, 0x51, 0x3A)};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Dice(float x, float y, int& level);

	bool rollEnd();

	void roll();
	sf::Vector2u valueRoll();
	~Dice();
};

#include "Dice.h"
#include"../Global/Support function.h"

Dice::~Dice()
{
	
	deleteObject(mersenne);
	deleteObject(random);
	for (auto& texture : resultRoll)
	{
		deleteObject(texture);
	}

}

void Dice::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	size_t& count = const_cast<size_t&>(countSprite);
	sf::RectangleShape* diceCOPY[2];

	for (int i = 0; i < 2; i++)
	{
		diceCOPY[i] = const_cast<sf::RectangleShape*>(&dice[i]);
		diceCOPY[i]->setTextureRect(sf::IntRect(countSprite * 50, 0, 50, 50));
		target.draw(dice[i]);
	}
	if (count == 179)
	{
		bool& variable = const_cast<bool&>(finish);
		variable = true;
	}
	else if (localTIME.getElapsedTime().asMilliseconds() > 16)
	{
		sf::Clock& time = const_cast<sf::Clock&>(localTIME);
		time.restart();
		count++;
	}
}

Dice::Dice(float x, float y)
{
	mersenne = new std::mt19937(reinterpret_cast<unsigned int>(this));
	random = new std::uniform_int_distribution<int>(0, 5);
	dice[0].setPosition(x, y);
	dice[1].setPosition(x + 210, y);
	dice[0].setSize(sf::Vector2f(200, 200));
	dice[1].setSize(sf::Vector2f(200, 200));

	resultRoll.resize(6);
	for (int i = 0; i < 6; i++)
	{
		resultRoll[i] = new sf::Texture;
		sf::String path = "resources//Image//Textures//roll_" + std::to_string(i+1) + ".png";
		loadTexture(path, resultRoll[i]);
		resultRoll[i]->setSmooth(true);
	}
}

void Dice::roll()
{
	finish = false;
	localTIME.restart();
	firstDice = (*random)(*mersenne);
	secondDice = (*random)(*mersenne);
	countSprite = 0;
	dice[0].setTexture(resultRoll[firstDice], true);
	dice[1].setTexture(resultRoll[secondDice], true);
}

bool Dice::rollEnd()
{
	return finish;
}

sf::Vector2u Dice::valueRoll()
{
	return sf::Vector2u(firstDice, secondDice);
}

#pragma once

#include<SFML/Graphics.hpp>
#include<random>

class Dice
{
	std::mt19937 *mersenne;
	std::uniform_int_distribution<int> *random;

	int roll();
public:
	Dice();
	~Dice();
};

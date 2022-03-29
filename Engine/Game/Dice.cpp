#include "Dice.h"

Dice::Dice()
{
	mersenne = new std::mt19937({ reinterpret_cast<std::mt19937::result_type>(this) });
	random = new std::uniform_int_distribution(0, 6);
}

int Dice::roll()
{
	return (*random)(*mersenne);
}

Dice::~Dice()
{
	delete mersenne;
	delete random;
}

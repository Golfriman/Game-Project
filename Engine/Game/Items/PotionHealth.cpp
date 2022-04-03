#include "PotionHealth.h"

PotionHealth::PotionHealth()
{
}

sf::String PotionHealth::show()
{
	return sf::String{};
}

void PotionHealth::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(1);
}

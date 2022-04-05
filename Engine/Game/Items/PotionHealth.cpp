#include "PotionHealth.h"

PotionHealth::PotionHealth()
{
}


void PotionHealth::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(1);
}

PotionHealth::~PotionHealth()
{
	delete textureItem;
	textureItem = nullptr;
}

#include "PotionHealth.h"

PotionHealth::PotionHealth()
{
}

void PotionHealth::show()
{
}

void PotionHealth::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(1);
}

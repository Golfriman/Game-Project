#include "PotionDamage.h"

PotionDamage::PotionDamage()
{
	//TODO доделать конструктор
}

void PotionDamage::use(Unit* unit)
{
	unit->getCharacteristics()->buff();
}

void PotionDamage::show()
{
	//Вывести на экран информацию о данном зелье
}

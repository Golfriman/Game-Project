#include "PotionDamage.h"

PotionDamage::PotionDamage()
{
	//TODO доделать конструктор
}

void PotionDamage::use(Unit* unit)
{
	unit->getCharacteristics()->buff();
}

sf::String PotionDamage::show()
{
	return sf::String{};
	//Вывести на экран информацию о данном зелье
}

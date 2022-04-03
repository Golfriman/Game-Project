#include "Bandages.h"

void Bandages::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(1);
	unit->getCharacteristics()->setBleeding(false);
}

sf::String Bandages::show()
{
	return sf::String{};
	//Вывести информацию
}

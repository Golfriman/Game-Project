#include "Bandages.h"

void Bandages::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(1);
	unit->getCharacteristics()->setBleeding(false);
}

void Bandages::show()
{
	//Вывести информацию
}

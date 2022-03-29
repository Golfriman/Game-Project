#include "Inventory.h"

Inventory::Inventory()
{
	resize(maxSizeInventory);
}

void Inventory::addItem(Items&& item)
{
	for (size_t i = 0; i < maxSizeInventory; i++)
	{
		if (at(i) == nullptr)
		{
			at(i) = &item;
			return;
		}
	}
}

void Inventory::removeItem(size_t position)
{
	delete at(position);
}

void Inventory::useItem(size_t position, Unit* hero)
{
	at(position)->use(hero);
}

void Inventory::showInfo(size_t position)
{
	at(position)->show();
}

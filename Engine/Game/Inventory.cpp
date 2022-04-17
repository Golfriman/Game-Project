#include "Inventory.h"

void Inventory::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 6; j++)
		{
			int id = i * 6 + j; // 7 - это максимум по одной стороне
			if (inventory[id])
			{
				inventory[id]->setPositionTexture(j * 153 + 506, 172 * i + 318);
				target.draw(*inventory[id]);
			}
		}
	}
}

Inventory::Inventory()
{
	inventory.resize(maxSizeInventory);
	Items* item = new Bandages;
	inventory[7] = std::move(item);
}

void Inventory::addItem(Items&& item)
{
	for (size_t i = 0; i < maxSizeInventory; i++)
	{
		if (inventory[i] == nullptr)
		{
			inventory[i] = &item;
			return;
		}
	}
}

void Inventory::removeItem(size_t position)
{
	delete inventory[position];
	inventory[position] = nullptr;
}

void Inventory::useItem(size_t position, Unit* hero)
{
	inventory[position]->use(hero);
	removeItem(position);
}

sf::String Inventory::showInfo(size_t position)
{
	return inventory[position]->show();
}

Items* Inventory::getItem(size_t position) const
{
	return inventory[position];
}

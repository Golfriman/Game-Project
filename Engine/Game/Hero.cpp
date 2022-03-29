#include"Hero.h"

Hero::Hero(Characteristics* character)
{
	this->characterisitcs = character;
	inventory = new Inventory;
}

void Hero::addInventory(Items* item)
{
	inventory->addItem(std::move(*item));
}

void Hero::execute()
{
}

Inventory* Hero::openInventory()
{
	return inventory;
}

uint16_t& Hero::getCoins()
{
	return coins;
}

void Hero::setCoins(uint16_t coins)
{
	this->coins = coins;
}

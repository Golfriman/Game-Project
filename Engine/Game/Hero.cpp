#include"Hero.h"

Hero::Hero(Characteristics* character, sf::Font* titleFont)
{
	spriteUnit->setPosition(300, 500);
	spriteUnit->setSize(sf::Vector2f(233.f, 450.f));
	this->characterisitcs = character;
	inventory = new Inventory;
	dice = new Dice(100, 100);
}

void Hero::attackWithASpecialAttack(Unit* unit)
{
	unit->setBlock();
}


void Hero::addInventory(Items* item)
{
	inventory->addItem(std::move(* item));
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

Dice& Hero::getDice()
{
	return *dice;
}

void Hero::setTextureHero(sf::Texture* textureHero)
{
	spriteUnit->setTexture(textureHero);
}

Hero::~Hero()
{
	delete inventory;
	inventory = nullptr;

	delete dice;
	dice = nullptr;
}

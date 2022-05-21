#include"Hero.h"

Hero::Hero(Characteristics* character)
{
	spriteUnit->setPosition(576.f,333.f);
	spriteUnit->setSize(sf::Vector2f(233, 450));
	this->characterisitcs = character;
	inventory = new Inventory;
	dice = new Dice(97.f, 850.f);
	no_modifyCharacteristics = new Characteristics(*character);
}

void Hero::attackWithASpecialAttack(Unit* unit)
{
	int16_t& number = this->characterisitcs->getNumberOfAction();
	if (number >= 3)
	{
		number -= 3;
		unit->setBlock();
		return;
	}
	std::cout << "haha\n";
	return;
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

void Hero::updateCharacteristics(sf::Vector2u diceValue)
{
	*no_modifyCharacteristics = *characterisitcs;
	auto update = [&](auto value)->void
	{
		switch (value)
		{
		case 1:
		{
			this->characterisitcs->changeCharacterisitics(1.1 * characterisitcs->getDamage(), 0, 0, 0, 0, 0);
			break;
		}
		case 2:
		{
			this->characterisitcs->changeCharacterisitics(0, 0, 0, 1.1*characterisitcs->getLucky(), 0, 0);
			break;
		}
		case 3:
		{
			this->characterisitcs->changeCharacterisitics(0, 0, 0, 0, 1.1*characterisitcs->getDexterity(), 0);
			break;
		}
		case 4:
		{
			this->characterisitcs->changeCharacterisitics(0.9 * characterisitcs->getDamage(), 0, 0, 0, 0, 0);
			break;
		}
		case 5:
		{
			this->characterisitcs->changeCharacterisitics(0, 0, 0, 0.9 * characterisitcs->getLucky(), 0, 0);
			break;
		}
		case 6:
		{
			this->characterisitcs->changeCharacterisitics(0, 0, 0, 0, 0.9 * characterisitcs->getDexterity(), 0);
			break;
		}
		}
	};
	update(diceValue.x);
	update(diceValue.y);
}

void Hero::setTextureHero(sf::Texture* textureHero)
{
	spriteUnit->setTexture(textureHero);
}

void Hero::resetCharacteristics()
{
	int healthPoint = characterisitcs->getHealthPoint();
	*characterisitcs = *no_modifyCharacteristics;
	characterisitcs->setHealth(healthPoint);
}


Hero::~Hero()
{
	delete inventory;
	inventory = nullptr;

	delete dice;
	dice = nullptr;

	delete no_modifyCharacteristics;
	no_modifyCharacteristics = nullptr;
}

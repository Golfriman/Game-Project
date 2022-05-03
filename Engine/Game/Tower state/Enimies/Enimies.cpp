#include"Enimies.h"

void Enimies::dropItem()
{
	std::mt19937 mersenne{ reinterpret_cast<unsigned>(this) };
	std::uniform_int_distribution<> nm{ 0, 100 };
	int var = nm(mersenne);
	if (var <= 50)
	{
		items = new PotionHealth();
	}
	else
	{
		items = new PotionDamage();
	}
}

Enimies::Enimies(float x, float y, sf::String path)
{
	characterisitcs = new Characteristics(50, 50, 1, 10, 1, 10);
	loadTexture(path, &text);
	spriteUnit->setTexture(&text);
	spriteUnit->setSize(static_cast<sf::Vector2f>(text.getSize()));
	spriteUnit->setPosition(x, y);
}

sf::Vector2f Enimies::getPosition()
{
	return spriteUnit->getPosition() + sf::Vector2f(0, spriteUnit->getSize().y);
}

sf::Vector2f Enimies::getSize()
{
	return spriteUnit->getSize();
}

bool Enimies::makeADecision(Hero* hero)
{
	if (this->getNumberOfAction() == 0)
	{
		this->characterisitcs->resetNumOfActionPerTurn();
		return false;
	}
	else if (this->getNumberOfAction() > 2)
	{
		this->attackWithAHeavyAttack(hero);
		
	}
	else
	{
		this->attackWithALightAttack(hero);
	}
	return true;
}

void Enimies::attackWithASpecialAttack(Unit* unit)
{
	std::cout << "Special attack";
}

void Enimies::execute()
{
}

Items* Enimies::kill()
{
	dropItem();
	return items;
}

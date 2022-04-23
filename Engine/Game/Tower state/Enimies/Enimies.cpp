#include"Enimies.h"

void Enimies::dropItem()
{
}

Enimies::Enimies(float x, float y, sf::String path)
{
	characterisitcs = new Characteristics(10, 10, 1, 10, 1, 10);
	loadTexture(path, &text);
	spriteUnit->setTexture(&text);
	spriteUnit->setSize(static_cast<sf::Vector2f>(text.getSize()));
	spriteUnit->setPosition(x, y);
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
	return nullptr;
}

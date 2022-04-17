#include"Enimies.h"

void Enimies::dropItem()
{
}

Enimies::Enimies(float x, float y)
{
	characterisitcs = new Characteristics(10, 10, 1, 10, 1, 10);
}

bool Enimies::makeADecision(Hero* hero)
{
	if (this->getNumberOfAction() == 0)
	{
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

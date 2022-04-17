#include"Characteristics.h"

Characteristics::Characteristics(uint8_t damage, uint8_t maxHP, uint8_t lucky, uint8_t dexterity, uint8_t numberOfActionsPerTurn, uint8_t armorPoints)
{
	this->damage = damage;
	this->healthPoint = maxHP;
	this->maxHealth = maxHP;
	this->lucky = lucky;
	this->dexterity = dexterity;
	this->numberOfActionsPerTurn = numberOfActionsPerTurn;
	this->armorPoints = armorPoints;
	this->isBuffHealth = false;
	this->isDebuffBleeding = false;
	this->decased = false;
}

void Characteristics::changeHealth(int8_t variable)
{
	if (variable < 0 && this->healthPoint < abs(variable))
	{
		decased = true;
		healthPoint = 0;
		return;
	}
	else if (maxHealth - healthPoint < variable)
	{
		healthPoint = maxHealth;
		return;
	}
	else
	{
		this->healthPoint = this->healthPoint+ variable;
		return;
	}
}

void Characteristics::changeCharacterisitics(uint8_t damage, uint8_t hp, uint8_t maxHP, uint8_t lucky, uint8_t dexterity, uint8_t numberOfActionsPerTurn)
{
	decased = false;
	this->damage += damage;
	this->healthPoint += hp;
	this->maxHealth += maxHP;
	this->lucky += lucky;
	this->dexterity += dexterity;
	this->numberOfActionsPerTurn += numberOfActionsPerTurn;
}

void Characteristics::setBuff(bool)
{
}

void Characteristics::setDebuff(bool variable)
{
}

void Characteristics::buff()
{
}

void Characteristics::debuff()
{
}

void Characteristics::changeArmorPoints(uint8_t armorPoints)
{
}

bool Characteristics::isDead()
{
	return decased;
}

void Characteristics::setBleeding(bool isBleeding)
{
	this->isDebuffBleeding = isBleeding;
}

uint8_t& Characteristics::getNumberOfAction()
{
	return numberOfActionsPerTurn;
}

uint8_t Characteristics::getDamage()
{
	return damage;
}

uint8_t Characteristics::getMaxHealth()
{
	return maxHealth;
}

uint8_t Characteristics::getHealthPoint()
{
	return healthPoint;
}

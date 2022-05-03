#include"Characteristics.h"

Characteristics::Characteristics(uint16_t damage, uint16_t maxHP, uint16_t lucky, uint16_t dexterity, uint16_t numberOfActionsPerTurn, uint16_t armorPoints)
{
	this->damage = damage;
	this->healthPoint = maxHP;
	this->maxHealth = maxHP;
	this->lucky = lucky;
	this->dexterity = dexterity;
	this->numberOfActionsPerTurn = numberOfActionsPerTurn;
	this->armorPoints = armorPoints;
	numberOfActionsPerTurn_copy = numberOfActionsPerTurn;
	this->isBuffHealth = false;
	this->isDebuffBleeding = false;
	this->decased = false;
}

void Characteristics::changeHealth(int16_t variable)
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

void Characteristics::changeCharacterisitics(uint16_t damage, uint16_t hp, uint16_t maxHP, uint16_t lucky, uint16_t dexterity, uint16_t numberOfActionsPerTurn)
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

void Characteristics::changeArmorPoints(uint16_t armorPoints)
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

uint16_t& Characteristics::getNumberOfAction()
{
	return numberOfActionsPerTurn;
}

uint16_t Characteristics::getDamage()
{
	return damage;
}

uint16_t Characteristics::getMaxHealth()
{
	return maxHealth;
}

uint16_t Characteristics::getHealthPoint()
{
	return healthPoint;
}

void Characteristics::resetNumOfActionPerTurn()
{
	numberOfActionsPerTurn = numberOfActionsPerTurn_copy;
}

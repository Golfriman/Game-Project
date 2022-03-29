#include"Characteristics.h"

Characteristics::Characteristics(uint8_t damage, uint8_t hp, uint8_t maxHP, uint8_t lucky, uint8_t dexterity, uint8_t numberOfActionsPerTurn, uint8_t armorPoints)
{
	this->damage = damage;
	this->healthPoint = hp;
	this->maxHealth = maxHP;
	this->lucky = lucky;
	this->dexterity = dexterity;
	this->numberOfActionsPerTurn = numberOfActionsPerTurn;
	this->armorPoints = armorPoints;
	this->isBuffHealth = false;
	this->isDebuffBleeding = false;
	this->decased = false;
}

void Characteristics::changeHealth(uint8_t variable)
{
	uint8_t temp = this->healthPoint + variable;
	if (temp > maxHealth)
	{
		this->healthPoint = maxHealth;
	}
	else if(temp < 0)
	{
		decased = true;
		healthPoint = -1;
	}
	else
	{
		this->healthPoint = temp;
	}
}

void Characteristics::changeCharacterisitics(uint8_t damage, uint8_t hp, uint8_t maxHP, uint8_t lucky, uint8_t dexterity, uint8_t numberOfActionsPerTurn)
{
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

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

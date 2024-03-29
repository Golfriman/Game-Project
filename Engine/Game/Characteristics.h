#pragma once
#include<iostream>
class Characteristics
{
	uint16_t damage;
	int16_t healthPoint;
	uint16_t maxHealth;
	uint16_t lucky;
	uint16_t dexterity;
	int16_t numberOfActionsPerTurn;
	uint16_t armorPoints;
	int16_t numberOfActionsPerTurn_copy;
	bool decased;
	bool isBuffHealth;
	bool isDebuffBleeding;
public:
	Characteristics(uint16_t damage, uint16_t maxHP, uint16_t lucky, uint16_t dexterity, int16_t numberOfActionsPerTurn, uint16_t armorPoints);
	void changeHealth(int16_t variable);
	void changeCharacterisitics(uint16_t damage, uint16_t hp, uint16_t maxHP, uint16_t lucky, uint16_t dexterity, uint16_t numberOfActionsPerTurn);
	void setBuff(bool variable);
	void setDebuff(bool variable);
	void buff();
	void debuff();
	void changeArmorPoints(uint16_t armorPoints);
	bool isDead();
	void setBleeding(bool isBleeding);
	int16_t& getNumberOfAction();
	uint16_t getDamage();
	uint16_t getMaxHealth();
	int16_t getHealthPoint();
	void setHealth(int16_t hp);
	void resetNumOfActionPerTurn();
	int16_t getDexterity();
	int16_t getLucky();
};

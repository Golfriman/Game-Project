#pragma once
#include<iostream>
class Characteristics
{
	uint8_t damage;
	uint8_t healthPoint;
	uint8_t maxHealth;
	uint8_t lucky;
	uint8_t dexterity;
	uint8_t numberOfActionsPerTurn;
	uint8_t armorPoints;
	uint8_t numberOfActionsPerTurn_copy;
	bool decased;
	bool isBuffHealth;
	bool isDebuffBleeding;
public:
	Characteristics(uint8_t damage, uint8_t maxHP, uint8_t lucky, uint8_t dexterity, uint8_t numberOfActionsPerTurn, uint8_t armorPoints);
	void changeHealth(int8_t variable);
	void changeCharacterisitics(uint8_t damage, uint8_t hp, uint8_t maxHP, uint8_t lucky, uint8_t dexterity, uint8_t numberOfActionsPerTurn);
	void setBuff(bool variable);
	void setDebuff(bool variable);
	void buff();
	void debuff();
	void changeArmorPoints(uint8_t armorPoints);
	bool isDead();
	void setBleeding(bool isBleeding);
	uint8_t& getNumberOfAction();
	uint8_t getDamage();
	uint8_t getMaxHealth();
	uint8_t getHealthPoint();
	void resetNumOfActionPerTurn();
};

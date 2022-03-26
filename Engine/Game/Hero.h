#pragma once

#include"Unit.h"
#include"Inventory.h"
#include"Dice.h"

class Hero : public Unit
{
	Inventory* inventory;
	uint16_t coins;
	Dice dice[2];
public:
	Hero(Characteristics* characteristics);
	void addInventory(Items* item);
	void execute();
	Inventory* openInventory();
	uint16_t& getCoins();
	void setCoins(uint16_t coins);
};

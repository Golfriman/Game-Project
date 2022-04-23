#pragma once

#include"Unit.h"
#include"Inventory.h"
#include"Dice.h"

class Hero : public Unit
{
	Inventory* inventory;
	uint16_t coins;
	Dice *dice;
	Characteristics* no_modifyCharacteristics;
public:
	Hero(Characteristics* characteristics);
	void attackWithASpecialAttack(Unit* unit) override;
	void addInventory(Items* item);
	Inventory* openInventory();
	uint16_t& getCoins();
	void setCoins(uint16_t coins);
	Dice& getDice();
	void updateCharacteristics(sf::Vector2u diceValue);
	void setTextureHero(sf::Texture* heroTexture);
	void resetCharacteristics();
	~Hero();
};

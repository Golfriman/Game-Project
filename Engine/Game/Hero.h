#pragma once

#include"Unit.h"
#include"Inventory.h"
#include"Dice.h"

class Hero : public Unit
{
	Inventory* inventory;
	uint16_t coins;
	Dice *dice;
public:
	Hero(Characteristics* characteristics, sf::Font* titleFont);
	void attackWithASpecialAttack(Unit* unit) override;
	void addInventory(Items* item);
	Inventory* openInventory();
	uint16_t& getCoins();
	void setCoins(uint16_t coins);
	Dice& getDice();
	void setTextureHero(sf::Texture* heroTexture);
	~Hero();
};

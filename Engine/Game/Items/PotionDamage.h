#pragma once

#include"Items.h"

class PotionDamage: public Items
{
	uint8_t timerBuff;
	uint8_t valueBuff;
public:
	PotionDamage();
	void use(Unit* unit) override;
	sf::String show() override;
};
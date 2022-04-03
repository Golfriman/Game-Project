#pragma once
#include"Items.h"

class PotionHealth : public Items
{
public:
	PotionHealth();
	sf::String show()override;
	void use(Unit* unit)override;
};
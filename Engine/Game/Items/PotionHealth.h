#pragma once
#include"Items.h"

class PotionHealth : public Items
{
public:
	PotionHealth();
	void show()override;
	void use(Unit* unit)override;
};
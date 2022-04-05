#pragma once
#include"Items.h"

class PotionHealth : public Items
{
public:
	PotionHealth();
	void use(Unit* unit)override;
	~PotionHealth();
};
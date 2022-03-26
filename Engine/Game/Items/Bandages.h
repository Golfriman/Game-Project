#pragma once

#include"Items.h"

class Bandages : public Items
{
public:
	void use(Unit* unit)override;
	void show()override;
};
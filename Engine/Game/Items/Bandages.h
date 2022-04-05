#pragma once

#include"Items.h"

class Bandages : public Items
{
public:
	Bandages();
	void use(Unit* unit)override;
	~Bandages();
};
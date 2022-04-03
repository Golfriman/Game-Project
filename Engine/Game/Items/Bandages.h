#pragma once

#include"Items.h"

class Bandages : public Items
{
public:
	void use(Unit* unit)override;
	sf::String show()override;
};
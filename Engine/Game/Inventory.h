#pragma once
#include<vector>
#include"Items/Items.h"
#include"Unit.h"


class Inventory : private std::vector<Items*>
{
	static constexpr uint8_t maxSizeInventory = 12;
public:
	Inventory();
	void addItem(Items&& item);
	void removeItem(size_t position);
	void useItem(size_t position, Unit* hero);
	sf::String showInfo(size_t position);
};
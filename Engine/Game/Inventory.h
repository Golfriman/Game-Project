#pragma once
#include<vector>
#include"Items/Items.h"
#include"Unit.h"


class Inventory : private std::vector<Items*>
{
	static constexpr uint8_t maxSizeInventory = 12;
	size_t postionCursor;
public:
	Inventory();
	void addItem(Items&& item);
	void removeItem(size_t position);
	void useItem(size_t position, Unit* hero);
	void showInfo(size_t position);
};
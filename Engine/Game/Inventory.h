#pragma once
#include<vector>
#include"Items/Items.h"
#include"Hero.h"

class Inventory : private std::vector<Items*>
{
	static constexpr uint8_t maxSizeInventory = 12;
	size_t postionCursor;
public:
	Inventory();
	void addItem(Items*&& item);
	void removeItem(size_t postion);
	void useItem(size_t position, Hero* hero);
	void showInfo(size_t postion);
};
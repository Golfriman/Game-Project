#pragma once
#include<vector>
#include"Items/Items.h"
#include"Items/Bandages.h"
#include"Items/PotionDamage.h"
#include"Items/PotionHealth.h"
#include"Unit.h"


class Inventory : public sf::Drawable
{
	std::vector<Items*> inventory;
	static constexpr uint8_t maxSizeInventory = 14;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	Inventory();
	void addItem(Items&& item);
	void removeItem(size_t position);
	void useItem(size_t position, Unit* hero);
	sf::String showInfo(size_t position);
	Items* getItem(size_t position) const;
	~Inventory()
	{
		for (auto& elem : inventory)
		{
			delete elem;
		}
	}
};
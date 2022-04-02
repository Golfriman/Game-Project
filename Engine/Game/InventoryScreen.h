#pragma once

#include"Hero.h"
#include"Tower state/TowerState.h"

class InventoryScreen: public TowerState
{
	Inventory* inventory;
public:
	InventoryScreen(System& system, Hero* hero);
	void update() override;
	void draw() override;
	void render() override;
	void createSource() override;
	void removeSource() override;
	void hud();
};
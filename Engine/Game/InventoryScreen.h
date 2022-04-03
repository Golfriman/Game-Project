#pragma once

#include"Hero.h"
#include"Tower state/TowerState.h"
#include"../Global/Button.h"
#include"../Global/Support function.h"

class InventoryScreen: public TowerState
{
	Inventory* inventory;
	std::vector<Button*> buttons;
	sf::Color red;
	sf::Color white;
	sf::Text* text;
	sf::Text itemInfo;
	void createUI();
public:
	InventoryScreen(System& system, Hero* hero);
	void update() override;
	void draw() override;
	void render() override;
	void createSource() override;
	void removeSource() override;
	void hud();
};
#pragma once

#include"Hero.h"
#include"Tower state/TowerState.h"
#include"../Global/Button.h"
#include"../Global/Support function.h"

class InventoryScreen: public TowerState
{
	Inventory* inventory;
	std::vector<Button*> buttonsInventoryScreen;
	std::vector<Button*> buttonsDropMenu;
	sf::Color red;
	sf::Color white;
	sf::Text* title;
	sf::Text* dropMenuUI;
	sf::Text* itemInfo;
	sf::Texture* texture;
	sf::Texture* inventoryAreaTexture;
	sf::RectangleShape textArea;
	sf::RectangleShape inventoryArea;
	size_t positionItem;
	size_t positionHoverItem;
	size_t positionDropMenu;
	size_t positionCreateDropMenu;
	bool isHover;
	bool isDropMenu;
	bool isCreated;
	void createUI();
	void createDropMenu();
	void removeDropMenu();
	std::function<void()> dropItem;
	std::function<void()> useItem;
public:
	InventoryScreen(System& system, Hero* hero);
	void update() override;
	void draw() override;
	void render() override;
	void createSource() override;
	void removeSource() override;
	void hud();
};
#include"InventoryScreen.h"

InventoryScreen::InventoryScreen(System& system, Hero* hero)
{
	this->inventory = hero->openInventory();
	init(system, hero);
}

void InventoryScreen::update()
{
}

void InventoryScreen::draw()
{
	std::cout << "Inventory\n";
}

void InventoryScreen::render()
{

}

void InventoryScreen::createSource()
{

}

void InventoryScreen::removeSource()
{
}

void InventoryScreen::hud()
{
	return;
}

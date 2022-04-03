#include"InventoryScreen.h"

void InventoryScreen::createUI()
{
	setText(L"Инвентарь", *text, titleFont, 839, 174, red, 48);
}

InventoryScreen::InventoryScreen(System& system, Hero* hero)
{
	this->inventory = hero->openInventory();
	init(system, hero);
	red = sf::Color::Red;
	white = sf::Color::White;
}

void InventoryScreen::update()
{
	sf::Event event;
	while (handle->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{

		}
	}
}

void InventoryScreen::draw()
{
	//handle->draw(inventory->showInfo(1));
	handle->draw(*text);
}

void InventoryScreen::render()
{
	//setText(inventory->showInfo(1), itemInfo, normallFont, 563, 802, white, 24);
}

void InventoryScreen::createSource()
{
	text = new sf::Text;
	createUI();
}

void InventoryScreen::removeSource()
{
	deleteObject(text);
}

void InventoryScreen::hud()
{
	return;
}

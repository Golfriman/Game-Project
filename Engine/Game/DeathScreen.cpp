#include "DeathScreen.h"

void DeathScreen::createUI()
{
	insertButton(0, buttons, 0, 0, 100, 100);
	setText(L"Начать заново", text[0], titleFont, 0, 0, colorText, 10);
	setText(L"Главное меню", text[0], titleFont, 0, 0, colorText, 10);
}

DeathScreen::DeathScreen(System& system, Hero* hero, bool* isLoadSreen)
{
	init(system, hero, isLoadSource);
	restartGame = [&]()->void
	{
		throw ID_GAME;
	};
	returnMainMenu = [&]()->void
	{
		throw ID_MENU;
	};
}

void DeathScreen::update()
{
}

void DeathScreen::render()
{
}

void DeathScreen::draw()
{
}

void DeathScreen::createSource()
{
	isDelete = false;
	text = new sf::Text[2];
}

void DeathScreen::removeSource()
{
	isDelete = true;
	deleteArrayObject(text);
}

#include "DeathScreen.h"

void DeathScreen::createUI()
{
	insertButton(0, buttons, 662, 647, 235, 50, &texture[1], &texture[2]);
	insertButton(1, buttons, 1033, 647, 235, 50, &texture[1], &texture[2]);

	buttons[0]->setOnClick(restartGame);
	buttons[1]->setOnClick(returnMainMenu);

	setText(L"Вы умерли", text[0], titleFont, 688, 401, colorText1, 128);
	setText(L"К сожалению, вы больше не сможете проснуться", text[1], normallFont, 662, 608, colorText1, 24);
	setText(L"Начать заново", text[2], normallFont, 677, 657, colorText0, 24);
	setText(L"Главное меню", text[3], normallFont, 1057, 657, colorText0, 24);
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
	if (event->type == sf::Event::MouseMoved)
	{
		sf::Vector2f coordinate = mouse->getCoordinate();
		for (auto& ui : buttons)
		{
			ui->setIdle();
			if (ui->containsCursor(coordinate))
			{
				ui->setHover();
			}
		}
	}
	else if (event->type == sf::Event::MouseButtonReleased)
	{
		if (event->key.code == sf::Mouse::Left)
		{
			sf::Vector2f coordinate = mouse->getCoordinate();
			for (auto& ui : buttons)
			{
				if (ui->containsCursor(coordinate))
				{
					ui->startClick();
				}
			}
		}
	}
}

void DeathScreen::render()
{
}

void DeathScreen::draw()
{
	handle->draw(desk);
	for (auto& ui : buttons)
	{
		handle->draw(ui->getRect());
	}
	for (int i = 0; i < 4; i++)
	{
		handle->draw(text[i]);
	}
}

void DeathScreen::hud()
{
}

void DeathScreen::createSource()
{
	isDelete = false;
	text = new sf::Text[4];
	texture = new sf::Texture[3];
	loadTexture("resources//Image//Textures//Death.png", &texture[0]);
	loadTexture("resources//Image//Textures//Button.png", &texture[1]);
	loadTexture("resources//Image//Textures//HoverButton1.png", &texture[2]);

	desk.setTexture(&texture[0], true);
	desk.setSize(sf::Vector2f(1058, 572));
	desk.setPosition(441, 254);
	createUI();

}

void DeathScreen::removeSource()
{
	if (isDelete)
	{
		return;
	}
	isDelete = true;
	deleteArrayObject(text);
	deleteArrayObject(texture);
	for (auto& ui : buttons)
	{
		deleteObject(ui);
	}
}

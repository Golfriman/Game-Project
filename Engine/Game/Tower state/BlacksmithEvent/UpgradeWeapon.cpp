#include"UpgradeWeapon.h"
 
void UpgradeWeapon :: createUI()
{
	insertButton(0, menuButton, 538, 717, 842, 322, &textureButton[0]);
	insertButton(1, menuButton, 915, 969, 90, 46, &textureButton[1]);

	


}

UpgradeWeapon::UpgradeWeapon(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);
}

void UpgradeWeapon::update()
{
	if (event->type == sf::Event::MouseMoved)
	{

	}
	else if (event->type == sf::Event::MouseButtonPressed)
	{
		if (event->key.code == sf::Mouse::Left)
		{
			sf::Vector2f cursor = mouse->getCoordinate();
			for (auto& ui : menuButton)
			{
				if (ui->containsCursor(cursor))
				{
					ui->startClick();
					return;
				}


			}
		}
	}
}

void UpgradeWeapon::render()
{
}

void UpgradeWeapon::draw()
{
	return;
}

void UpgradeWeapon::hud()
{
	for (auto& ui : menuButton)
	{
		handle->draw(ui->getRect());
	}
}

void UpgradeWeapon::createSource()
{
	textureButton = new sf::Texture[2];
	white = new sf::Color(sf::Color::White);
	loadTexture("resources//Image//Textures//weaponFrame.png", &textureButton[0]);
	loadTexture("resources//Image//Textures//blacksmithArrows.png", &textureButton[1]);
	createUI();
}

void UpgradeWeapon::removeSource()
{
	deleteArrayObject(textureButton);
}

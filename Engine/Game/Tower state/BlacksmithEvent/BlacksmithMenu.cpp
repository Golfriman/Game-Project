#include "BlacksmithMenu.h"

void BlacksmithMenu::createUI()
{
	insertButton(0, menuButton, 1500, 201, 359, 100, &textureButton[0]);
	setText("Talk about tower", textButton[0], normallFont, 1529, 229, *white, 36);
	menuButton[0]->setOnClick(pressToTalk);

	insertButton(1, menuButton, 1500, 321, 359, 100, &textureButton[0]);
	setText("Modification arms", textButton[1], normallFont, 1515,349, *white, 36);
	menuButton[1]->setOnClick(pressToMod);

	insertButton(2, menuButton, 1500, 440, 359, 100, &textureButton[0]);
	setText("Get away", textButton[2], normallFont, 1583, 469, *white, 36);
	menuButton[2]->setOnClick(pressToExit);


}

BlacksmithMenu::BlacksmithMenu(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);

	pressToTalk = [&]()
	{
		throw ID_TALK_B;
	};
	pressToMod = [&]()
	{
		throw ID_MOD_B;
	};
	pressToExit = [&]()
	{
		throw ID_EXIT_B;
	};
	

	
	

}

void BlacksmithMenu::update()
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

void BlacksmithMenu::render()
{
	
}

void BlacksmithMenu::draw()
{
	return;
}

void BlacksmithMenu::hud()
{
	for (auto& ui : menuButton)
	{
		handle->draw(ui->getRect());
	}

	for (int i = 0; i < 3; i++)
	{
		handle->draw(textButton[i]);
	}
}

void BlacksmithMenu::createSource()
{
	textureButton = new sf::Texture[1];
	white = new sf::Color(sf::Color::White);
	commandAreaTexture = new sf::Texture;
	textButton = new sf::Text[3];
	loadTexture("resources//Image//Textures//rect.png", &textureButton[0]);
	createUI();

}

void BlacksmithMenu::removeSource()
{
	deleteArrayObject(textureButton);
	deleteArrayObject(textButton);
	/*deleteObject(white);
	deleteObject(commandAreaTexture);
	deleteObject(area);*/

}

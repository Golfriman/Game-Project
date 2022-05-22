#include "BlacksmithMenu.h"

void BlacksmithMenu::createUI()
{    
	board.setPosition(1476, 150);
	board.setSize(sf::Vector2f(407, 442));
	board.setTexture(&textureButton[1], true);
	insertButton(0, menuButton, 1509, 201, 341, 100, &textureButton[0], &textureButton[2]);
	setText(L"Поговорить\nс кузнецом", textButton[0], normallFont, 1563, 207, *white, 36);
	menuButton[0]->setOnClick(pressToTalk);

	insertButton(1, menuButton, 1509, 321, 341, 100, &textureButton[0], &textureButton[2]);
	setText(L"Улучшить\nпредметы", textButton[1], normallFont, 1583,328, *white, 36);
	menuButton[1]->setOnClick(pressToMod);

	insertButton(2, menuButton, 1509, 440, 341, 100, &textureButton[0], &textureButton[2]);
	setText(L"Уйти", textButton[2], normallFont, 1635, 469, *white, 36);
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
			sf::Vector2f cursor = mouse->getCoordinate();
			for (auto& ui : menuButton)
			{
				ui->setIdle();
				if (ui->containsCursor(cursor))
				{
					ui->setHover();
				}
			}
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
	handle->draw(board);
	for (auto& ui : menuButton)
	{
		handle->draw(ui->getRect());
	}

	for (int i = 0; i < 3; i++)
	{
		handle->draw(textButton[i]);
	}
};

void BlacksmithMenu::createSource()
{
	textureButton = new sf::Texture[3];
	white = new sf::Color(sf::Color::White);
	commandAreaTexture = new sf::Texture;
	textButton = new sf::Text[3];
	loadTexture("resources//Image//Textures//RandomEventButton.png", &textureButton[0]);
	loadTexture("resources//Image//Textures//BlackSmithSquare.png", &textureButton[1]);
	textureButton[2].setSmooth(true);
	loadTexture("resources//Image//Textures//HoverButton0.png", &textureButton[2]);
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

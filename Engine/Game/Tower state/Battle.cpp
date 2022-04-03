#include"Battle.h"

void Battle::createUI()
{
	insertButton(0, buttons, 552, 950, 238, 49, &texture[0]);
	setText(L"Легкая атака", text[0], normallFont, 591, 960, *white, 24);
	//Функция для кнопки

	insertButton(1, buttons, 841, 950, 238, 49, &texture[1]);
	setText(L"Тяжелая атака", text[1], normallFont, 871, 960, *white, 24);

	insertButton(2, buttons, 1132, 950, 238, 49, &texture[0]);
	setText(L"Парирование", text[2], normallFont, 1164, 960, *white, 24);

	insertButton(3, buttons, 841, 793, 238, 49, &texture[2]);
	setText(L"Передать ход", text[3], normallFont, 875, 808, *white, 24);

}

Battle::Battle(System& system, Hero* hero)
{
	turnPlayer = true;
	init(system, hero);
}

void Battle::update()
{
	sf::Event event;
	while (handle->pollEvent(event))
	{
		if (turnPlayer)
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				/*Что делает пользователь во время своего хода не считая общего игрового интерфейса*/
			}
		}
	}
}

void Battle::render()
{
}

void Battle::draw()
{
	
	
	handle->draw(wall);
}

void Battle::hud()
{
	for (auto& ui : buttons)
	{
		handle->draw(ui->getRect());
	}
	for (size_t i = 0; i < 4; i++)
	{
		handle->draw(text[i]);
	}
}

void Battle::createSource()
{
	isDelete = false;
	wallpaper = new sf::Texture;
	loadTexture("resources//Image//Textures//1st floor.png", wallpaper);
	/*Случайным образом создаем врагов*/
	white = new sf::Color(sf::Color::White);
	texture = new sf::Texture[3];
	text = new sf::Text[4];
	loadTexture("resources//Image//Textures//teal.png", &texture[0]);
	loadTexture("resources//Image//Textures//red.png", &texture[1]);
	loadTexture("resources//Image//Textures//Color(28,25,37).png", &texture[2]);
	wall.setTexture(*wallpaper);
	createUI();
}

void Battle::removeSource()
{
	for (auto& ui : buttons)
	{
		deleteObject(ui);
	}
	buttons.clear();

	deleteArrayObject(texture);
	deleteArrayObject(text);
	deleteObject(white);
	deleteObject(wallpaper);


	isDelete = true;
}

Battle::~Battle()
{
	if (!isDelete)
	{
		this->removeSource();
	}
}

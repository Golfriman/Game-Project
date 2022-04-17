#include "Game.h"
#include"Engine.h"

void Game::generateLevel(System& system)
{
	std::vector<TowerState*> levelGame;
	mersenne->seed(reinterpret_cast<unsigned int>(this));
	std::random_device rm;
	std::uniform_int_distribution<int> battle(5, 7);
	std::uniform_int_distribution<int> randomEvents(5, 6);

	for (size_t i = 0, size = battle(*mersenne); i < size; i++)
	{
		levelGame.push_back(new Battle(system, hero, level, isLoadSource));
	}

	for (size_t i = 0, size = randomEvents(*mersenne); i < size; i++)
	{
		levelGame.push_back(new RandomEvent(system, hero, isLoadSource));
	}

	std::shuffle(levelGame.begin(), levelGame.end(), rm);
	for (int i = 0, size = levelGame.size(); i < size; i++)
	{
		towerstates.push_back(levelGame[i]);
	}

	towerstates.push_back(new BlackSmith(system, hero, isLoadSource ));
}

void Game::createUI()
{
	//Кнопка инвентаря
	insertButton(0, buttons, 1454, 954, 80, 77, /*Текстуры*/&texture[1]);
	buttons[0]->setOnClick(clickInventory);
	//Кнопка выпадающего меню в углу
	insertButton(1, buttons, 35, 34, 80, 80, /*Текстуры*/ &texture[0]);
	buttons[1]->setOnClick(clickDropMenu);

	setText(L"Dream Tower уровень", *infoLevel, titleFont, 150, 49, *white, 48);
	setText(std::to_string(level), *numberLevel, titleFont, 580, 49, *white, 48);

	//Кнопка продолжить
	setText(L"Продолжить", text[0], normallFont, 115, 35, *white, 36);
	insertButton(2, buttons, 115, 35, 280, 50, &texture[2]);
	buttons[2]->setOnClick(clickDropMenu);
	//Кнопка начать заново
	setText(L"Перезапуск", text[1], normallFont, 115, 85, *white, 36);
	insertButton(3, buttons, 115, 85, 280, 50, &texture[2]);
	buttons[3]->setOnClick(clickRestart);
	//Кнопка настройки
	setText(L"Настройки", text[2], normallFont, 115, 135, *white, 36);
	insertButton(4, buttons, 115, 135, 280, 50, &texture[2]);
	buttons[4]->setOnClick(clickSettings);
	//Кнопка выйти в главное меню
	setText(L"Главное меню", text[3], normallFont, 115, 185, *white, 36);
	insertButton(5, buttons, 115, 185, 280, 50, &texture[2]);
	buttons[5]->setOnClick(clickMainMenu);
}

Game::Game(System& system, bool *isLoadSource)
{
	isDropMenu = false;
	this->isLoadSource = isLoadSource;
	this->system = &system;
	initSystemComponent(system);
	showHUD = true;
	hero = nullptr;
	mersenne = nullptr;
	isDelete = true;

	clickInventory = [this]()->void {
		if (!isPressedInventory)
		{
			lastID = idGame;
			idGame = idInventory;
			isPressedInventory = !isPressedInventory;
		}
		else
		{
			idGame = lastID;
			isPressedInventory = !isPressedInventory;
		}
	};
	clickDropMenu = [this]()->void
	{
		isDropMenu = !isDropMenu;
	};
	clickRestart = [this]() {
		this->removeSource();
		this->createSource();
	};
	clickSettings = [this]() {
		std::cout << "Settings";
		/*if (!isPressedSettings)
		{
			lastID = idGame;
			idGame = idSettings;
			isPressedSettings = !isPressedSettings;
		}
		else
		{
			idGame = lastID;
			isPressedSettings = !isPressedSettings;
		}*/
	};
	clickMainMenu = [this]()
	{
		throw - 1;
	};

}

void Game::createSource()
{
	*isLoadSource = false;
	isDelete = false;
	isDropMenu = false;
	idGame = 1;
	isPressedInventory = false;
	isPressedSettings = false;
	mersenne = new std::mt19937({ reinterpret_cast<unsigned int>(this) });
	hero = new Hero(new Characteristics(5, 255, 3, 4, 5, 1), titleFont);
	inventoryScreen = new InventoryScreen(*system, hero);
	towerstates.push_back(inventoryScreen);
	level = 1;
	isPressedInventory = false;
	//Генерируем первый этаж, так как не имеет смысла держать другие этажи
	generateLevel(*system);
	towerstates[idGame]->createSource();
	towerstates[0]->createSource();
	texture = new sf::Texture[3];
	white = new sf::Color(sf::Color::White);
	text = new sf::Text[4];
	infoLevel = new sf::Text;
	numberLevel = new sf::Text;
	loadTexture("resources//Image//Textures//burger.png", &texture[0]);
	loadTexture("resources//Image//Textures//inventory.png", &texture[1]);
	loadTexture("resources//Image//Textures//teal.png", &texture[2]);
	textureHero = new sf::Texture;
	textureHero->setSmooth(true);
	loadTexture("resources//Image//Textures//heroFloor1.png", textureHero);
	hero->setTextureHero(textureHero);
	createUI();

	*isLoadSource = true;
}

void Game::removeSource()
{
	isDelete = true;
	towerstates[idInventory]->removeSource();
	if (idGame == idInventory)
	{
		towerstates[lastID]->removeSource();
	}
	else
	{
		towerstates[idGame]->removeSource();
	}
	for (size_t i = 0, size = towerstates.size(); i < size; i++)
	{
		deleteObject(towerstates[i]);
	}
	deleteObject(textureHero);
	towerstates.clear();
	deleteObject(mersenne);
	deleteObject(hero);
	deleteObject(infoLevel);
	deleteArrayObject(texture);
	deleteArrayObject(text);
	deleteObject(white);
	deleteObject(numberLevel);
	for (auto& elem : buttons)
	{
		deleteObject(elem);
	}
	buttons.clear();
	level = 1;
	isDropMenu = false;
}

void Game::update()
{
	try {
		while (handle->pollEvent(*event))
		{

			if (event->type == sf::Event::KeyReleased)
			{
				if (event->key.code == keyboard->getConfig("Escape"))
				{
					clickDropMenu();
				}
				if (event->key.code == keyboard->getConfig("I"))
				{
					clickInventory();
				}
				if (event->key.code == keyboard->getConfig("H"))
				{
					showHUD = !showHUD;
				}
			}
			if (event->type == sf::Event::Closed)
			{
				handle->close();
				break;
			}
			if (event->type == sf::Event::MouseMoved)
			{

			}
			if (event->type == sf::Event::MouseButtonPressed)
			{
				if (event->key.code == sf::Mouse::Left)
				{
					sf::Vector2f coordinate = mouse->getCoordinate();
					for (int i = 0; i < 2; i++)
					{
						if (buttons[i]->containsCursor(coordinate))
						{
							buttons[i]->startClick();
							return;
						}
					}
					if (isDropMenu)
					{
						for (int i = 2; i < 6; i++)
						{
							if (buttons[i]->containsCursor(coordinate))
							{
								buttons[i]->startClick();
								return;
							}
						}
					}
				}
			}
			towerstates[idGame]->update();
		}
	}
	catch(int id) {
		if (id >= 0 && id < towerstates.size())
		{
			towerstates[idGame]->removeSource();
			*isLoadSource = false;
			sf::Thread createSource([this, id]() { towerstates[id]->createSource(); });
			createSource.launch();
			sf::Clock clock;
			sf::Text text;
			text.setFont(*titleFont);
			while (!isLoadSource)
			{
				
				sf::String point;
				sf::String string = "Loading";
				
				if (clock.getElapsedTime().asMilliseconds() > 200)
				{
					point = point.getSize() >= 5 ? "" : point + ".";
					clock.restart();
				}
				handle->clear();
				text.setString(string + point);
				handle->draw(text);
				handle->display();
			}
			idGame = id;
		}
		else if (id == -1)
		{
			throw 0;
		}
		else
		{
			for (int i = 1, size = towerstates.size(); i < size; i++)
			{
				deleteObject(towerstates[i]);
			}
			generateLevel(*system);
			idGame = 1;
			level++;
			sf::String path = "resources//Image//Textures//heroFloor" + std::to_string(level) + ".png";
			loadTexture(path, textureHero);
			hero->setTextureHero(textureHero);
			numberLevel->setString(std::to_string(level));
		}
	}
}

void Game::render()
{
	towerstates[idGame]->render();
}

void Game::draw()
{
	towerstates[idGame]->draw();
	if (showHUD || isPressedInventory)
	{
		handle->draw(buttons[0]->getRect());
		handle->draw(buttons[1]->getRect());

		if (isDropMenu)
		{
			for (int i = 0; i < 4; i++)
			{
				handle->draw(buttons[i + 2]->getRect());
				handle->draw(text[i]);
			}
		}
		else
		{
			handle->draw(*infoLevel);
			handle->draw(*numberLevel);
		}
		towerstates[idGame]->hud();
	}
}

Game::~Game()
{
	if (!isDelete)
	{
		this->removeSource();
	}
}

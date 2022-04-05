#include "Game.h"

void Game::generateLevel(System& system)
{
	std::vector<TowerState*> level;
	mersenne->seed(reinterpret_cast<unsigned int>(this));
	std::random_device rm;
	std::uniform_int_distribution<int> battle(5, 7);
	std::uniform_int_distribution<int> randomEvents(5, 6);

	for (size_t i = 0, size = battle(*mersenne); i < size; i++)
	{
		level.push_back(new Battle(system, hero));
	}

	for (size_t i = 0, size = randomEvents(*mersenne); i < size; i++)
	{
		level.push_back(new RandomEvent(system, hero));
	}

	std::ranges::shuffle(level, rm);
	for (int i = 0, size = level.size(); i < size; i++)
	{
		towerstates.push_back(level[i]);
	}

	towerstates.push_back(new BlackSmith(system, hero));
}

void Game::createUI()
{
	//������ ���������
	insertButton(0, buttons, 1454, 954, 80, 77, /*��������*/&texture[1]);
	buttons[0]->setOnClick(clickInventory);
	//������ ����������� ���� � ����
	insertButton(1, buttons, 35, 34, 80, 80, /*��������*/ &texture[0]);
	buttons[1]->setOnClick(clickDropMenu);

	setText(L"Dream Tower �������", *infoLevel, titleFont, 150, 49, *white, 48);
	setText(std::to_string(level), *numberLevel, titleFont, 580, 49, *white, 48);

	//������ ����������
	setText(L"����������", text[0], normallFont, 115, 35, *white, 36);
	insertButton(2, buttons, 115, 35, 280, 50, &texture[2]);
	buttons[2]->setOnClick(clickDropMenu);
	//������ ������ ������
	setText(L"����������", text[1], normallFont, 115, 85, *white, 36);
	insertButton(3, buttons, 115, 85, 280, 50, &texture[2]);
	buttons[3]->setOnClick(clickRestart);
	//������ ���������
	setText(L"���������", text[2], normallFont, 115, 135, *white, 36);
	insertButton(4, buttons, 115, 135, 280, 50, &texture[2]);
	buttons[4]->setOnClick(clickSettings);
	//������ ����� � ������� ����
	setText(L"������� ����", text[3], normallFont, 115, 185, *white, 36);
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
	hero = new Hero(new Characteristics(5, 20, 3, 4, 5, 1));
	inventoryScreen = new InventoryScreen(*system, hero);
	towerstates.push_back(inventoryScreen);
	level = 1;
	isPressedInventory = false;
	//���������� ������ ����, ��� ��� �� ����� ������ ������� ������ �����
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
					for (auto& ui : buttons)
					{
						if (ui->containsCursor(coordinate))
						{
							ui->startClick();
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
			towerstates[id]->createSource();
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

#include"Battle.h"

void Battle::createUI()
{
	insertButton(0, buttons, 552, 950, 238, 49, &texture[0]);
	setText(L"Легкая атака", text[0], normallFont, 591, 960, *white, 24);
	buttons[0]->setOnClick(commandHero[0]);

	insertButton(1, buttons, 841, 950, 238, 49, &texture[1]);
	setText(L"Тяжелая атака", text[1], normallFont, 871, 960, *white, 24);
	buttons[1]->setOnClick(commandHero[1]);

	insertButton(2, buttons, 1132, 950, 238, 49, &texture[0]);
	setText(L"Парирование", text[2], normallFont, 1164, 960, *white, 24);
	buttons[2]->setOnClick(commandHero[2]);

	insertButton(3, buttons, 841, 793, 238, 49, &texture[2]);
	setText(L"Передать ход", text[3], normallFont, 875, 808, *white, 24);
	buttons[3]->setOnClick(passToMove);
}

Battle::Battle(System& system, Hero* hero, int level, bool*isLoadingSource)
{
	this->levelGenerate = level;
	turnPlayer = true;
	trigger = -1;
	init(system, hero, isLoadingSource);
	commandHero[0] = [&]()
	{
		if (trigger == -1)
		{
			std::cout << "LOG: Enimie wasn't selected\n";
			return;
		}
		hero->attackWithALightAttack(enimiesInTheRoom[trigger]);
		if(enimiesInTheRoom[trigger]->isDead())
		{
			dropItems.push_back(enimiesInTheRoom[trigger]->kill());
			auto endItem = dropItems.rbegin();
			(*endItem)->setPositionTexture(0, 0);
			insertButton(trigger, dropItemsButton, 0, 0, 0, 0);
		}
	};
	commandHero[1] = [&]() {
		if (trigger = -1)
		{
			std::cout << "LOG: Enimie wasn't selected\n";
			return;
		}
		hero->attackWithAHeavyAttack(enimiesInTheRoom[trigger]);
		if(enimiesInTheRoom[trigger]->isDead())
		{
			dropItems.push_back(enimiesInTheRoom[trigger]->kill());
			auto endItem = dropItems.rbegin();
			(*endItem)->setPositionTexture(0, 0);
			insertButton(trigger, dropItemsButton, 0, 0, 0, 0);
		}
	};
	commandHero[2] = [&]()
	{
		if (trigger == -1)
		{
			std::cout << "LOG: Enimie wasn't selected\n";
			return;
		}
		hero->attackWithASpecialAttack(enimiesInTheRoom[trigger]);
	};
	passToMove = [&]()
	{
		std::cout << "Pass to move\n";
		turnPlayer = false;
	};
}

void Battle::update()
{
	if (!hero->getDice().rollEnd())
	{
		return;
	}
	//После того как закончатся противники, то есть возможность куда-нибудь потыкать
	else if (enimiesInTheRoom.size() == 0)
	{
		if (event->type == sf::Event::MouseMoved)
		{
			sf::Vector2f cursor = mouse->getCoordinate();
		}
		else if (event->type == sf::Event::MouseButtonPressed)
		{
			if (event->key.code == sf::Mouse::Left)
			{
				sf::Vector2f cursor = mouse->getCoordinate();
				int i = 0;
				for (auto& item : dropItemsButton)
				{
					/*if (item->containsCursor(cursor))
					{
						auto itemBegin = dropItems.begin();
						for (int j = 0; j < i; j++)
						{
							itemBegin++;
						}
						hero->addInventory(*itemBegin);
					}*/
				}
			}
		}
	}
	else if (turnPlayer)
	{
		if (event->type == sf::Event::MouseMoved)
		{
			sf::Vector2f coordinate = mouse->getCoordinate();
			for (auto& ui : buttons)
			{
				if (ui->containsCursor(coordinate))
				{
					//Переключить флаг на true когда будут исходники
					isHover = false;
					idHoverButton = ui->getState();
					return;
				}
			}
		}
		else if (event->type == sf::Event::MouseButtonPressed)
		{
			if (event->key.code == sf::Mouse::Left)
			{
				sf::Vector2f coordinate = mouse->getCoordinate();
				for (auto& ui : buttons)
				{
					if (ui->containsCursor(coordinate))
					{
						ui->startClick();
						trigger = -1;
						return;
					}
				}
			}
		}
	}
	else
	{
		bool turn = enimiesInTheRoom[monsterID]->makeADecision(hero);
		//0 - это номер нашего игрока
		healthBars[0]->update();
		if (!turn)
		{
			monsterID++;
			if (monsterID > enimiesInTheRoom.size() - 1)
			{
				std::cout << "Pass to move\n";
				turnPlayer = true;
				//Восстановить герою его кол-во действий.
				hero->getCharacteristics()->resetNumOfActionPerTurn();
				for (auto& enimie : enimiesInTheRoom)
				{
					enimie->getCharacteristics()->resetNumOfActionPerTurn();
				}
				monsterID = 0;
			}
		}
	}

}

void Battle::render()
{
	if (isHover)
	{
		buttons[idHoverButton]->setHover();
		isHover = false;
	}
}

void Battle::draw()
{
	handle->draw(wall);
	handle->draw(*hero);
	for (auto& enimie : enimiesInTheRoom)
	{
		handle->draw(*enimie);
	}
}

void Battle::hud()
{
	handle->draw(*area);
	for (auto& ui : buttons)
	{
		handle->draw(ui->getRect());
	}
	for (size_t i = 0; i < 4; i++)
	{
		handle->draw(text[i]);
	}
	for (auto& item : dropItems)
	{
		handle->draw(*item);
	}
	handle->draw(hero->getDice());

	for (auto& bar : healthBars)
	{
		handle->draw(*bar);
	}
}

void Battle::createSource()
{
	isDelete = false;
	wallpaper = new sf::Texture;

	monsterID = 0;
	std::uniform_int_distribution<int> numEnimies(1, 3);
	std::random_device rd;

	white = new sf::Color(sf::Color::White);
	texture = new sf::Texture[3];
	commandAreaTexture = new sf::Texture;
	text = new sf::Text[4];
	loadTexture("resources//Image//Textures//teal.png", &texture[0]);
	loadTexture("resources//Image//Textures//red.png", &texture[1]);
	loadTexture("resources//Image//Textures//Color(28,25,37).png", &texture[2]);
	loadTexture("resources//Image//Textures//command Area.png", commandAreaTexture);
	commandAreaTexture->setSmooth(true);
	area = new sf::RectangleShape;
	area->setSize(sf::Vector2f(935.f, 133.f));
	area->setPosition(494, 898);
	area->setTexture(commandAreaTexture, true);
	createUI();

	hero->getDice().roll();
	//Значение броска влияют на характеристики героя
	hero->updateCharacteristics(hero->getDice().valueRoll());

	std::mt19937 randomEngine{ reinterpret_cast<unsigned>(this) };
	std::uniform_int_distribution<> nEnimies{ 1, 3 };
	int var = 1;//nEnimies(randomEngine);
	enimiesInTheRoom.resize(1);
	healthBars.resize(1 + var);
	//Health bar heo 
	
	healthBars[0] = new HealthBar(500, 490, titleFont, hero);

	//Generate Enimies
	// Правила размещение врагов? Кол-во от 1 до 3
	switch (levelGenerate)
	{
	case 1:
	{
		loadTexture("resources//Image//Textures//1st floor.png", wallpaper);
		//Как генерируем врага?
		for (size_t i = 0; i < var; i++)
		{
			enimiesInTheRoom[i] = new Enimies(1300, 500, "resources//Image//Textures//spider.png");
			healthBars[i + 1] = new HealthBar(1300, 800, titleFont, enimiesInTheRoom[i]);
		}
		break;
	}
	case 2:
	{
		loadTexture("resources//Image//Textures//2nd floor.png", wallpaper);
		for (size_t i = 0; i < var; i++)
		{

		}
		break;
	}
	case 3:
	{
		loadTexture("resources//Image//Textures//3rd floor.png", wallpaper);
		for (size_t i = 0; i < var; i++)
		{

		}
		break;
	}
	//Продолжение следует
	}
	wall.setTexture(*wallpaper);
	*isLoadSource = true;
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
	deleteObject(commandAreaTexture);
	deleteObject(area);

	for (auto& enimie : enimiesInTheRoom)
	{
		deleteObject(enimie);
	}
	for (auto& hp : healthBars)
	{
		deleteObject(hp);
	}
	healthBars.clear();
	enimiesInTheRoom.clear();
	//Устанавливаем не модифицированные характеристики
	hero->resetCharacteristics();
	isDelete = true;
}

Battle::~Battle()
{
	if (!isDelete)
	{
		this->removeSource();
	}
}

Battle::HealthBar::HealthBar(float xPos, float yPos, sf::Font* font, Unit* unitInit)
{
	hp.setSize(sf::Vector2f(324, 33));
	max.setSize(sf::Vector2f(324, 33));
	max.setFillColor(sf::Color(0xffffff00));
	max.setOutlineColor(sf::Color(0x8c, 0x19, 00));
	max.setOutlineThickness(2.f);
	hp.setFillColor(sf::Color(0x8c, 0x19, 00));
	hp.setPosition(xPos, yPos);
	max.setPosition(xPos, yPos);
	infoHealth.setFont(*font);
	infoHealth.setPosition(xPos, yPos);
	infoHealth.setFillColor(sf::Color::White);
	unit = unitInit;

	float numHP = unit->getCharacteristics()->getHealthPoint();
	float numMAX = unit->getCharacteristics()->getMaxHealth();
	sf::String stringHealth = std::to_string((sf::Uint8)numHP) + '/' + std::to_string((sf::Uint8)numMAX);
	infoHealth.setString(stringHealth);
	hp.setSize(sf::Vector2f(324 * numHP / numMAX, 33));
}

void Battle::HealthBar::update()
{
	sf::Text& text = const_cast<sf::Text&>(infoHealth);
	float numHP = unit->getCharacteristics()->getHealthPoint();
	float numMAX = unit->getCharacteristics()->getMaxHealth();
	sf::String stringHealth = std::to_string((sf::Uint8)numHP) + '/' + std::to_string((sf::Uint8)numMAX);
	text.setString(stringHealth);
	sf::RectangleShape& healthRect = const_cast<sf::RectangleShape&>(hp);
	healthRect.setSize(sf::Vector2f(324 * numHP / numMAX, 33));
}

void Battle::HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(max);
	target.draw(hp);
	target.draw(infoHealth);
}

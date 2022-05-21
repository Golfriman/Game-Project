#include"Battle.h"

void Battle::createUI()
{
	insertButton(0, buttons, 552, 950, 238, 49, &textureButtonUI[0], &textureButtonUI[3]);
	setText(L"Легкая атака", text[0], normallFont, 591, 960, *white, 24);
	buttons[0]->setOnClick(commandHero[0]);

	insertButton(1, buttons, 841, 950, 238, 49, &textureButtonUI[1], &textureButtonUI[4]);
	setText(L"Тяжелая атака", text[1], normallFont, 871, 960, *white, 24);
	buttons[1]->setOnClick(commandHero[1]);

	insertButton(2, buttons, 1132, 950, 238, 49, &textureButtonUI[0], &textureButtonUI[3]);
	setText(L"Парирование", text[2], normallFont, 1164, 960, *white, 24);
	buttons[2]->setOnClick(commandHero[2]);

	insertButton(3, buttons, 841, 793, 238, 49, &textureButtonUI[2], &textureButtonUI[5]);
	setText(L"Передать ход", text[3], normallFont, 875, 801, *white, 24);
	buttons[3]->setOnClick(passToMove);
}

Battle::Battle(System& system, Hero* hero, int level, bool*isLoadingSource)
{
	this->levelGenerate = level;
	turnPlayer = true;
	trigger = MONSTER_NOT_SELECTED;
	init(system, hero, isLoadingSource);
	commandHero[LIGHT_ATTACK] = [&]()
	{
		if (trigger == MONSTER_NOT_SELECTED)
		{
			std::cout << "LOG: Enimie wasn't selected\n";
			return;
		}
		this->hero->attackWithALightAttack(enimiesInTheRoom[trigger]);
		healthBars[trigger + 1]->update();
		if(enimiesInTheRoom[trigger]->isDead())
		{
			dropItems.push_back(enimiesInTheRoom[trigger]->kill());
			auto endItem = dropItems.rbegin();
			sf::Vector2f positionItem = enimiesInTheRoom[trigger]->getPosition();
			(*endItem)->setPositionTexture(positionItem.x, positionItem.y);
			insertButton(dropItems.size(), dropItemsButton, positionItem.x, positionItem.y, 118, 137);

			//При смерти монстра мы удаляем его
			auto itMonster = enimiesInTheRoom.begin();
			for (int i = 0; i < trigger; i++)
			{
				++itMonster;
			}
			enimiesInTheRoom.erase(itMonster);
			trigger = MONSTER_NOT_SELECTED;
		}
	};
	commandHero[HEAVY_ATTACK] = [&]() {
		if (trigger == MONSTER_NOT_SELECTED)
		{
			std::cout << "LOG: Enimie wasn't selected\n";
			return;
		}
		this->hero->attackWithAHeavyAttack(enimiesInTheRoom[trigger]);
		healthBars[trigger + 1]->update();
		if(enimiesInTheRoom[trigger]->isDead())
		{
			dropItems.push_back(enimiesInTheRoom[trigger]->kill());
			auto endItem = dropItems.rbegin();
			sf::Vector2f positionItem = enimiesInTheRoom[trigger]->getPosition();
			(*endItem)->setPositionTexture(positionItem.x, positionItem.y);
			insertButton(dropItems.size(), dropItemsButton, positionItem.x, positionItem.y, 118, 137);

			auto itMonster = enimiesInTheRoom.begin();
			for (int i = 0; i < trigger; i++)
			{
				++itMonster;
			}
			enimiesInTheRoom.erase(itMonster);
			trigger = MONSTER_NOT_SELECTED;
		}
	};
	commandHero[SPECIAL_ATTACK] = [&]()
	{
		if (trigger == MONSTER_NOT_SELECTED)
		{
			std::cout << "LOG: Enimie wasn't selected\n";
			return;
		}
		this->hero->attackWithASpecialAttack(enimiesInTheRoom[trigger]);
	};
	passToMove = [&]()
	{
		std::cout << "Pass to move\n";
		turnPlayer = false;
	};
	next = []()
	{
		throw ID_NEXT;
	};
}

void Battle::update()
{
	if (!hero->getDice().rollEnd())
	{
		return;
	}
	//После того как закончатся противники, то есть возможность куда-нибудь потыкать
	else if (enimiesInTheRoom.empty())
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
					if (item->containsCursor(cursor))
					{
						auto itemBegin = dropItems.begin();
						for (int j = 0; j < i; j++)
						{
							itemBegin++;
						}
						hero->addInventory(*itemBegin);
						dropItems.erase(itemBegin);
					}
				}
				if (exitUI->containsCursor(cursor))
				{
					exitUI->startClick();
					return;
				}

				if (exitUI->containsCursor(cursor))
				{
					exitUI->startClick();
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
				ui->setIdle();
				if (ui->containsCursor(coordinate))
				{
					ui->setHover();
				}
			}
			for (int i = 0; i < enimiesUI.size(); i++)
			{
				if (enimiesUI[i]->containsCursor(coordinate))
				{
					isHoverEnimie = true;
					idHoverEnimie = i;
					return;
				}
			}
			enimiesUI[idHoverEnimie]->setIdle();
			//buttons[idHoverButton]->getIdle();
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
						return;
					}
				}
				for (auto& ui : enimiesUI)
				{
					if (ui->containsCursor(coordinate))
					{
						trigger = idHoverEnimie;
						std::cout << trigger << '\n';
						return;
					}
				}
			}
		}
	}

}

void Battle::render()
{
	if (isHoverEnimie)
	{
		enimiesUI[idHoverEnimie]->setHover();
		isHoverEnimie = false;
	}
	if (!turnPlayer)
	{
		bool turn = enimiesInTheRoom[monsterID]->makeADecision(hero);
		healthBars[HERO_HEALTHBAR]->update();
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
	if (trigger != MONSTER_NOT_SELECTED)
	{
		enimiesUI[trigger]->setActive();
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
	if (enimiesInTheRoom.empty())
	{
		handle->draw(exitUI->getRect());
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
	if (!enimiesInTheRoom.empty())
	{
		for (auto& ui : enimiesUI)
		{
			handle->draw(ui->getRect());
		}
	}
}

void Battle::createSource()
{
	isDelete = false;
	wallpaper = new sf::Texture;
	isHoverEnimie = false;
	idHoverEnimie = 0;
	monsterID = 0;
	std::uniform_int_distribution<int> numEnimies(1, 3);
	std::random_device rd;

	white = new sf::Color(sf::Color::White);
	textureButtonUI = new sf::Texture[6];
	textureButtonEnimies = new sf::Texture[3];
	commandAreaTexture = new sf::Texture;
	text = new sf::Text[4];
	loadTexture("resources//Image//Textures//RandomEventButton.png", &textureButtonUI[0]);
	loadTexture("resources//Image//Textures//Button.png", &textureButtonUI[1]);
	loadTexture("resources//Image//Textures//Color(28,25,37).png", &textureButtonUI[2]);
	loadTexture("resources//Image//Textures//HoverButton0.png", &textureButtonUI[3]);
	loadTexture("resources//Image//Textures//HoverButton1.png", &textureButtonUI[4]);
	loadTexture("resources//Image//Textures//HoverButton2.png", &textureButtonUI[5]);
	loadTexture("resources//Image//Textures//command Area.png", commandAreaTexture);
	loadTexture("resources//Image//Textures//transparent.png", &textureButtonEnimies[0]);
	
	commandAreaTexture->setSmooth(true);
	area = new sf::RectangleShape;
	area->setSize(sf::Vector2f(935.f, 133.f));
	area->setPosition(494.f, 898.f);
	area->setTexture(commandAreaTexture, true);
	createUI();

	hero->getDice().roll();
	//Значение броска влияют на характеристики героя
	hero->updateCharacteristics(hero->getDice().valueRoll());

	std::mt19937 randomEngine{ reinterpret_cast<unsigned>(this) };
	std::uniform_int_distribution<> nEnimies{ 1, 3 };
	int var = 1;//nEnimies(randomEngine);
	healthBars.resize(1 + var);
	exitRoom = new sf::Texture;
	healthBars[HERO_HEALTHBAR] = new HealthBar(414.f, 793.f, titleFont, hero);

	//Generate Enimies
	// Правила размещение врагов? Кол-во от 1 до 3
	switch (levelGenerate)
	{
	case 1:
	{
		loadTexture("resources//Image//Textures//1st floor.png", wallpaper);
		loadTexture("resources//Image//Textures//door 1st floor.png", exitRoom);
		//Как генерируем врага?
		for (size_t i = 0; i < var; i++)
		{
			loadTexture("resources//Image//Textures//spider2.png", &textureButtonEnimies[1]);
			loadTexture("resources//Image//Textures//spider3.png", &textureButtonEnimies[2]);
			enimiesInTheRoom.push_back(new Enimies(1300, 450, "resources//Image//Textures//spider1.png"));
			healthBars[i + 1] = new HealthBar(1300, 793, titleFont, enimiesInTheRoom[i]);
			sf::Vector2f size = enimiesInTheRoom[i]->getSize();
			insertButton(i, enimiesUI, 1300, 450, size.x, size.y, &textureButtonEnimies[0], &textureButtonEnimies[1], &textureButtonEnimies[2]);
		}
		break;
	}
	case 2:
	{
		loadTexture("resources//Image//Textures//2nd floor.png", wallpaper);
		loadTexture("resources//Image//Textures//door 2st floor.png", exitRoom);
		for (size_t i = 0; i < var; i++)
		{
			loadTexture("resources//Image//Textures//monster2.png", &textureButtonEnimies[1]);
			loadTexture("resources//Image//Textures//monster3.png", &textureButtonEnimies[2]);
			enimiesInTheRoom.push_back(new Enimies(1300, 450, "resources//Image//Textures//monster1.png"));
			healthBars[i + 1] = new HealthBar(1300, 793, titleFont, enimiesInTheRoom[i]);
			sf::Vector2f size = enimiesInTheRoom[i]->getSize();
			insertButton(i, enimiesUI, 1300, 450, size.x, size.y, &textureButtonEnimies[0], &textureButtonEnimies[1], &textureButtonEnimies[2]);
		}
		break;
	}
	case 3:
	{
		loadTexture("resources//Image//Textures//3rd floor.png", wallpaper);
		loadTexture("resources//Image//Textures//door 3st floor.png", exitRoom);
		for (size_t i = 0; i < var; i++)
		{
			loadTexture("resources//Image//Textures//necromancer2.png", &textureButtonEnimies[1]);
			loadTexture("resources//Image//Textures//necromancer3.png", &textureButtonEnimies[2]);
			enimiesInTheRoom.push_back(new Enimies(1300, 450, "resources//Image//Textures//necromancer1.png"));
			healthBars[i + 1] = new HealthBar(1300, 793, titleFont, enimiesInTheRoom[i]);
			sf::Vector2f size = enimiesInTheRoom[i]->getSize();
			insertButton(i, enimiesUI, 1300, 450, size.x, size.y, &textureButtonEnimies[0], &textureButtonEnimies[1], &textureButtonEnimies[2]);
		}
		break;
	}
	//Продолжение следует
	}
	wall.setTexture(*wallpaper);
	short int xPos(1716), yPos(0), width(206), height(670);
	exitUI = new Button(0, xPos, yPos, width, height, exitRoom);
	exitUI->setOnClick(next);
	*isLoadSource = true;
}

void Battle::removeSource()
{
	for (auto& ui : buttons)
	{
		deleteObject(ui);
	}
	buttons.clear();
	deleteObject(exitRoom);
	deleteObject(exitUI);
	deleteArrayObject(textureButtonUI);
	deleteArrayObject(textureButtonEnimies);
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
	for (auto& ui : enimiesUI)
	{
		deleteObject(ui);
	}
	for (auto& item : dropItems)
	{
		deleteObject(item);
	}
	for (auto& ui : dropItemsButton)
	{
		deleteObject(ui);
	}
	enimiesUI.clear();
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

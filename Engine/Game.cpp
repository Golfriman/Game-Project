#include "Game.h"

void Game::generateLevel(System& system)
{
	std::vector<TowerState*> level;
	std::uniform_int_distribution<int> battle(5, 7);
	std::uniform_int_distribution<> randomEvents(5, 6);

	for (size_t i = 0, size = battle(*mersenne); i < size; i++)
	{
		level.push_back(new Battle(system));
	}

	for (size_t i = 0, size = randomEvents(*mersenne); i < size; i++)
	{
		level.push_back(new RandomEvent(system));
	}

	std::ranges::shuffle(level, *mersenne);
	std::ranges::for_each(level, [&](TowerState* event)
	{
		towerstates.push_back(event);
	});

	towerstates.push_back(new BlackSmith(system));
}

Game::Game(System& system, bool *isLoadSource)
{
	idGame = 0;
	
	this->isLoadSource = isLoadSource;
	this->system = &system;
	handle = system.getHandle();
	showHUD = true;
	hero = nullptr;
	mersenne = nullptr;
}

void Game::createSource()
{
	*isLoadSource = false;
	mersenne = new std::mt19937({ reinterpret_cast<std::mt19937::result_type>(this) });
	generateLevel(*system);
	//Генерируем первый этаж, так как не имеет смысла держать другие этажи
	towerstates[idGame]->createSource();
	*isLoadSource = true;
}

void Game::removeSource()
{
	std::ranges::for_each(towerstates, [](TowerState* event)
		{
			delete event;
		});
	towerstates.clear();
	delete mersenne;
}

void Game::update()
{
	try {
		towerstates[idGame]->update();
		sf::Event event;
		while (handle->pollEvent(event))
		{
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == keyboard->getConfig("Escape"))
				{
					/*Что-то про появление экрана паузы или что-то такое*/
				}
				if (event.key.code == keyboard->getConfig("I"))
				{
					/*Что-то про появление экрана инвентаря*/
				}
				if (event.key.code == keyboard->getConfig("H"))
				{
					showHUD = !showHUD;
				}
			}
			if (event.type == sf::Event::Closed)
			{
				handle->close();
			}
		}
	}
	catch(int id) {
		if (id > 0)
		{
			towerstates[idGame]->removeSource();
			towerstates[id]->createSource();
			idGame = id;
		}
		else
		{
			throw abs(id);
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
	if (showHUD)
	{
		towerstates[idGame]->hud();
	}
}

Game::~Game()
{
	std::ranges::for_each(towerstates, [](TowerState* event)
		{
			deleteObject(event);
		});
	towerstates.clear();
	deleteObject(mersenne);
}

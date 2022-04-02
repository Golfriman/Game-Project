#include"Battle.h"

Battle::Battle(System& system, Hero* hero)
{
	init(system, hero);
}

void Battle::update()
{
	sf::Event event;
	while (handle->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{

		}
	}
}

void Battle::render()
{
}

void Battle::draw()
{
	std::cout << "Battle\n";
}

void Battle::hud()
{
}

void Battle::createSource()
{
}

void Battle::removeSource()
{
}

Battle::~Battle()
{
}

#include"Battle.h"

Battle::Battle(System& system)
{
	initSystemComponent(system);
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

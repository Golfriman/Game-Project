#include "RandomEvent.h"


RandomEvent::RandomEvent(System& system, Hero* hero, bool*isLoadSource)
{
	init(system, hero, isLoadSource);
}

void RandomEvent::update()
{
	
}

void RandomEvent::render()
{
}

void RandomEvent::draw()
{
}

void RandomEvent::hud()
{
	
}

void RandomEvent::createSource()
{
	*isLoadSource = true;
}

void RandomEvent::removeSource()
{
}

RandomEvent::~RandomEvent()
{
}

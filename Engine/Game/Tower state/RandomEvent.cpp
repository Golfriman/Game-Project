#include "RandomEvent.h"

/*Описываем все наши функции тут потому что я не хочу чтобы они были доступны из вне*/
/*Также можно попробовать тут описать константы*/

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
	/*...*/
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

#include"Dialog.h"

Dialog::Dialog(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);
}

void Dialog::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		/*Отслеживаем движение мыши*/
	}
}

void Dialog::render()
{
}

void Dialog::draw()
{
}

void Dialog::hud()
{
	/*...*/
}

void Dialog::createSource()
{
}

void Dialog::removeSource()
{
}

#include"Farewell.h"

Farewell::Farewell(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);
}

void Farewell::update()
{
	throw ID_NEXT;
}

void Farewell::render()
{
}

void Farewell::draw()
{
}

void Farewell::hud()
{
	/*...*/
}

void Farewell::createSource()
{
}

void Farewell::removeSource()
{
}

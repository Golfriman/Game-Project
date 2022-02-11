#include "Exit.h"

Exit::Exit(System& system)
{
	window = system.getHandle();
}

void Exit::removeSource()
{
	return;
}

void Exit::createSource()
{
	return;
}

void Exit::update()
{
	window->close();
}

void Exit::render()
{
	return;
}

void Exit::draw()
{
	return;
}
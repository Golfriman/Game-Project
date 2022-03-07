#include "Exit.h"

Exit::Exit(System& system)
{
	handle = system.getHandle();
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
	handle->close();
}

void Exit::render()
{
	return;
}

void Exit::draw()
{
	return;
}
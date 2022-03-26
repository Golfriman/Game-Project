#include "Exit.h"

Exit::Exit(System& system, bool* isLoadSource)
{
	this->isLoadSource = isLoadSource;
	handle = system.getHandle();
}

void Exit::removeSource()
{
	return;
}

void Exit::createSource()
{
	*isLoadSource = true;
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
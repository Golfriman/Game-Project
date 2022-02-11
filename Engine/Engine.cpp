#include "Engine.h"
#include<iostream>

Engine::Engine()
{
	stateGame.resize(5);
	stateGame[0] = new Menu(system);
	stateGame[1] = new Game(system);
	stateGame[2] = new Settings(system);
	stateGame[3] = new Journal(system);
	stateGame[4] = new Exit(system);
	state = &system.getState();
	window = system.getHandle();
	stateEngine = *state;
	stateGame[*state]->createSource();
}

void Engine::update()
{
	system.getHandle()->clear();
	stateGame[*state]->update();
	if (stateEngine != *state)
	{
		stateGame[stateEngine]->removeSource();
		stateGame[*state]->createSource();
		stateEngine = *state;
	}
}

void Engine::render()
{
	stateGame[*state]->render();
}

void Engine::draw()
{
	stateGame[*state]->draw();
	system.getHandle()->display();
}

bool Engine::windowIsOpen()
{
	return window->isOpen();
}

Engine::~Engine()
{
	stateGame[*state]->removeSource();
	for (auto& object : stateGame)
	{
		deleteObject(object);
	}
}
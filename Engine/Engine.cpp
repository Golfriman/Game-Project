#include "Engine.h"
#include<iostream>

void Engine::showLoadScreen()
{
	sf::Clock clock;
	while (!isLoadSource)
	{
		sf::Text text;
		sf::String point;
		sf::String string = "Loading";
		text.setFont(*system.getTitleFont());
		if (clock.getElapsedTime().asMilliseconds() > 200)
		{
			point = point.getSize() >= 5 ? "" : point + ".";
			clock.restart();
		}
		window->clear();
		text.setString(string + point);
		window->draw(text);
		window->display();
	}
}

Engine::Engine()
{
	isLoadSource = false;
	stateGame.resize(5);
	stateGame[0] = new Menu(system, &isLoadSource);
	stateGame[1] = new Game(system, &isLoadSource);
	stateGame[2] = new Settings(system, &isLoadSource);
	stateGame[3] = new Journal(system, &isLoadSource);
	stateGame[4] = new Exit(system, &isLoadSource);
	window = system.getHandle();
	stateEngine = 0;
	stateGame[stateEngine]->createSource();
	system.getAudio().playBackgroundMusic(system.getAudio().getBackgroundPath("Crushed Dreams"));
}

void Engine::update()
{
	system.getHandle()->clear();
	try {
		stateGame[stateEngine]->update();
	}
	catch(int id) {
		stateGame[stateEngine]->removeSource();
		isLoadSource = false;
		sf::Thread createSource([this, id]() { stateGame[id]->createSource(); });
		createSource.launch();
		showLoadScreen();
		stateEngine = id;
	}
}

void Engine::render()
{
	stateGame[stateEngine]->render();
}

void Engine::draw()
{
	stateGame[stateEngine]->draw();
	system.getHandle()->display();
}

bool Engine::windowIsOpen()
{
	return window->isOpen();
}

Engine::~Engine()
{
	stateGame[stateEngine]->removeSource();
	for (auto object : stateGame)
	{
		deleteObject(object);
	}
	stateGame.clear();
}

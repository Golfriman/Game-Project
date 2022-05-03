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
		text.setFont(*system->getTitleFont());
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
	system = new System;
	isLoadSource = false;
	stateGame = { 
		std::make_pair(ID_MENU, new Menu(*system, &isLoadSource)),
		std::make_pair(ID_GAME, new Game(*system, &isLoadSource)),
		std::make_pair(ID_SETTINGS, new Settings(*system, &isLoadSource, ID_MENU)),
		std::make_pair(ID_JOURNAL, new Journal(*system, &isLoadSource)),
		std::make_pair(ID_EXIT, new Exit(*system, &isLoadSource))
	};
	window = system->getHandle();
	stateEngine = ID_MENU;
	stateGame[stateEngine]->createSource();
	system->getAudio().playBackgroundMusic(system->getAudio().getBackgroundPath("Crushed Dreams"));
}

void Engine::update()
{
	system->getHandle()->clear();
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
	window->display();
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
		deleteObject(object.second);
	}
	stateGame.clear();
	deleteObject(system);
}

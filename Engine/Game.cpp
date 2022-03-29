#include "Game.h"

Game::Game(System& system, bool *isLoadSource)
{
	idGame = -1;
	idTowerStates = new size_t(- 1);
	towerstates.resize(15);
	this->isLoadSource = isLoadSource;
	initSystemComponent(system);
}

void Game::createSource()
{
	/*Загрузка ресурсов*/
}

void Game::removeSource()
{
	/*Удаление ресурсов*/
}

void Game::update()
{
	towerstates[idGame]->update();
	if (idGame != *idTowerStates)
	{
		towerstates[idGame]->removeSource();
		towerstates[*idTowerStates]->createSource();
		idGame = *idTowerStates;
	}
}

void Game::render()
{
	towerstates[idGame]->render();
	return;
}

void Game::draw()
{

	towerstates[idGame]->draw();
	return;
}
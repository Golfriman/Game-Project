#include "Game.h"

Game::Game(System& system, bool *isLoadSource)
{
	this->isLoadSource = isLoadSource;
	state = &system.getState();
	handle = system.getHandle();
	keyboard = &system.getKeyboard();
	text = nullptr;
	white = nullptr;
}

void Game::createSource()
{
	white = new sf::Color(sf::Color::White);
	text = new sf::Text;
	setText("Game", *text, titleFont, 220, 15, *white, 10);
	*isLoadSource = true;
}

void Game::removeSource()
{
	deleteObject(white);
	deleteObject(text);
}

void Game::update()
{
	sf::Event event;
	while (handle->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			handle->close();
		}
	}
}

void Game::render()
{
	return;
}

void Game::draw()
{
	handle->draw(*text);
	return;
}
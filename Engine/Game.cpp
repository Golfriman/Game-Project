#include "Game.h"

Game::Game(System& system)
{
	state = &system.getState();
	window = system.getHandle();
	keyboard = &system.getKeyboard();
	font = nullptr;
	text = nullptr;
	white = nullptr;
}

void Game::createSource()
{
	white = new sf::Color(sf::Color::White);
	font = new sf::Font;
	loadFont("resources\\Fonts\\sansation.ttf", *font);
	text = new sf::Text;
	setText("Game", *text, *font, 220, 15, *white, 10);
}

void Game::removeSource()
{
	deleteObject(white);
	deleteObject(font);
	deleteObject(text);
}

void Game::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

void Game::render()
{
	return;
}

void Game::draw()
{
	window->draw(*text);
	return;
}
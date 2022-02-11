#include "Journal.h"

Journal::Journal(System& system)
{
	window = system.getHandle();
	state = &system.getState();
	keyboard = &system.getKeyboard();
	white = nullptr;
	font = nullptr;
	text = nullptr;
}

void Journal::createSource()
{
	white = new sf::Color(sf::Color::White);
	font = new sf::Font;
	loadFont("resources\\Fonts\\sansation.ttf", *font);
	text = new sf::Text;
	setText("Journal", *text, *font, 220, 15, *white, 10);
}

void Journal::removeSource()
{
	deleteObject(white);
	deleteObject(font);
	deleteObject(text);
}

void Journal::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().escape))
			{
				*state = 0;
			}
		}
	}
}

void Journal::render()
{
	return;
}

void Journal::draw()
{
	window->draw(*text);
	return;
}

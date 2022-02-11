#include "Settings.h"

Settings::Settings(System& system)
{
	state = &system.getState();
	audio = &system.getAudio();
	handle = system.getHandle();
	keyboard = &system.getKeyboard();
	font = nullptr;
	text = nullptr;
	white = nullptr;
}

void Settings::createSource()
{
	white = new sf::Color(sf::Color::White);
	font = new sf::Font;
	loadFont("resources\\Fonts\\sansation.ttf", *font);
	text = new sf::Text;
	setText("Settings", *text, *font, 220, 15,*white, 10);
}

void Settings::removeSource()
{
	deleteObject(font);
	deleteObject(text);
	deleteObject(white);
}

void Settings::update()
{
	sf::Event event;
	if (handle->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			handle->close();
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

void Settings::render()
{
	return;
}

void Settings::draw()
{
	handle->draw(*text);
	return;
}

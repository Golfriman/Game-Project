#include "Journal.h"

Journal::Journal(System& system)
{
	window = system.getHandle();
	mouse = system.getMouse();
	state = &system.getState();
	keyboard = &system.getKeyboard();
	audio = &system.getAudio();
	titleFont = system.getTitleFont();
	normallFont = system.getNormalFont();
	white = nullptr;
	text = nullptr;
	texture = nullptr;
	idle = nullptr;
	isDelete = false;
}

void Journal::createSource()
{
	isDelete = false;
	white = new sf::Color(sf::Color::White);
	idle = new sf::Color(0, 0, 255);
	text = new sf::Text[2];
	setText("Journal", text[0], *titleFont, 800, 64, *white, 64);
	sf::String rus = u8"Здесь ничего нет. Просто разработчики устали, пока делали другое...";
	sf::String str = sf::String::fromUtf8(rus.begin(), rus.end());
	setText(str, text[1], *normallFont, 10, 200, *white, 36);
	texture = new sf::Texture;
	loadTexture("resources\\Image\\Textures\\dream.jpg", texture);
	rect.setTexture(texture);
	rect.setSize(sf::Vector2f(626, 626));
	rect.setPosition(647, 327);
	insertButton(0, buttonJournal, buttonJournalPoint, 100, 900, 187, 50, 36, "Back", normallFont, *white, idle);
}

void Journal::removeSource()
{
	isDelete = true;
	deleteObject(white);
	deleteObject(idle);
	deleteArrayObject(text);
	for (auto& coordinate : buttonJournalPoint)
	{
		deleteObject(buttonJournal[coordinate]);
	}
	deleteObject(texture);
	buttonJournal.clear();
	buttonJournalPoint.clear();
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
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().escape) || sf::Keyboard::isKeyPressed(keyboard->getConfig().accept))
			{
				sound.setBuffer(audio->getEffects("Click"));
				*state = 0;
				sound.setVolume(audio->getEffectVolume());
				sound.play();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2f convert = mouse->getCoordinate();
				Coordinate cursor{ convert.x, convert.y };
				if (buttonJournal[cursor])
				{
					sound.setBuffer(audio->getEffects("Click"));
					*state = 0;
					sound.setVolume(audio->getEffectVolume());
					sound.play();
				}
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
	if (!isDelete)
	{
		for (int i = 0; i < 2; i++)
		{
			window->draw(text[i]);
		}
		window->draw(rect);
		for (auto& coordinate : buttonJournalPoint)
		{
			window->draw(buttonJournal[coordinate]->getRect());
			window->draw(*buttonJournal[coordinate]->getText());
		}
	}
	return;
}

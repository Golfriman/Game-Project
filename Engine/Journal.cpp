#include "Journal.h"

Journal::Journal(System& system, bool *isLoadSource)
{
	this->isLoadSource = isLoadSource;
	handle = system.getHandle();
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
	setText("Journal", text[0], titleFont, 800, 64, *white, 64);
	sf::String rus = "I'm boring";
	setText(rus, text[1], normallFont, 10, 200, *white, 36);
	texture = new sf::Texture;
	loadTexture("resources//Image//Textures//dream.jpg", texture);
	rect.setTexture(texture);
	rect.setSize(sf::Vector2f(626, 626));
	rect.setPosition(647, 327);
	insertButton(0, buttonJournal, 100, 900, 187, 50);
	*isLoadSource = true;
}

void Journal::removeSource()
{
	isDelete = true;
	deleteObject(white);
	deleteObject(idle);
	deleteArrayObject(text);
	for (auto& object : buttonJournal)
	{
		deleteObject(object);
	}
	deleteObject(texture);
	buttonJournal.clear();
}

void Journal::update()
{
	sf::Event event;
	while (handle->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			handle->close();
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig("Escape")))
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
				for (auto& object : buttonJournal)
				{
					if (object->containsCursor(convert))
					{
						sound.setBuffer(audio->getEffects("Click"));
						*state = 0;
						sound.setVolume(audio->getEffectVolume());
						sound.play();
						break;
					}
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
			handle->draw(text[i]);
		}
		handle->draw(rect);
		for (auto& object : buttonJournal)
		{
			handle->draw(object->getRect());
		}
	}
	return;
}

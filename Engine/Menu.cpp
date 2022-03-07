#include"Menu.h"

Menu::Menu(System& system)
{

	subMenu.resize(2);
	subMenu[0] = new subState::MainMenu(system, &substate);
	subMenu[1] = new subState::ExitMenu(system, &substate);
	substate = 0;
	isDelete = false;
}

void Menu::createSource()
{
	isDelete = false;
	for (auto& object : subMenu)
	{
		object->createSource();
	}
}

void Menu::removeSource()
{
	isDelete = true;
	for (auto& object : subMenu)
	{
		object->deleteSource();
	}
}

void Menu::update()
{
	subMenu[substate]->update();
}

void Menu::render()
{
	subMenu[substate]->render();
}

void Menu::draw()
{
	if (!isDelete)
	{
		subMenu[substate]->draw();
	}
}

Menu::~Menu()
{
	for (auto& object : subMenu)
	{
		deleteObject(object);
	}
	subMenu.clear();
}

subState::MainMenu::MainMenu(System& system, int* substate)
{
	audio = &system.getAudio();
	window = system.getHandle();
	keyboard = &system.getKeyboard();
	state = &system.getState();
	mouse = system.getMouse();
	titleFont = system.getTitleFont();
	normalFont = system.getNormalFont();
	transparency = nullptr;
	highlight = nullptr;
	menuWallpaper = nullptr;
	text = nullptr;
	last = { -1, -1 };
	isPressed = false;
	stateNow = 0;
	stateLast = 0;
	this->substate = substate;
	sound.setVolume(audio->getEffectVolume());
}

void subState::MainMenu::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
		if (event.type == sf::Event::KeyPressed && !(isPressed))
		{
			isPressed = true;
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().up))
			{
				stateLast = stateNow;
				stateNow = stateNow - 1 >= 0 ? stateNow - 1 : 3;
			}
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().down))
			{
				stateLast = stateNow;
				stateNow = stateNow + 1 < 4 ? stateNow + 1 : 0;
			}
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().accept))
			{
				
				playClickEffect();
				*state = stateNow + 1;
			}
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().escape))
			{
				*substate = 1;
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			isPressed = false;
		}
		if (event.type == sf::Event::MouseMoved)
		{
			sf::Vector2f convert = mouse->getCoordinate();
			for (auto& object : menu)
			{
				if (object->containsCursor(last) && object->getStateColor() == 1)
				{
					stateLast = object->getState();
					break;
				}
			}
			for (auto& object : menu)
			{
				if (object->containsCursor(convert) && object->getStateColor() == 0)
				{
					last = convert;
					menu[stateNow]->setIdle();
					stateNow = object->getState();
					break;
				}
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2f cursor = mouse->getCoordinate();
				for (auto& object : menu)
				{
					if (object->containsCursor(cursor))
					{
						playClickEffect();
						*state = stateNow + 1;
						break;
					}
				}
			}
		}
	}
}

void subState::MainMenu::render()
{
	menu[stateLast]->setIdle();
	menu[stateNow]->setHover();
}

void subState::MainMenu::draw()
{
	sf::Sprite wall(*menuWallpaper);
	window->draw(wall);
	for (int i = 0; i < 4; i++)
	{
		window->draw(menu[i]->getRect());

		window->draw(text[i]);
	}
}

void subState::MainMenu::createSource()
{
	transparency = new sf::Texture;
	highlight = new sf::Texture;
	loadTexture("resources//Image//Textures//red.png", highlight);
	loadTexture("resources//Image//Textures//transparent.png", transparency);
	menuWallpaper = new sf::Texture;
	loadTexture("resources//Image//Textures//tower2.jpg", menuWallpaper);
	string[0] = "Start Game";
	string[1] = "Settings";
	string[2] = "Journal";
	string[3] = "Exit";
	text = new sf::Text[4];
	sf::Color white = sf::Color::White;
	for (int i = 0; i < 4; i++)
	{
		insertButton(i, menu, 20, 700 + i * 35, 200, 30, transparency, highlight);
		setText(string[i], text[i], normalFont, 20, 700 + i * 35, white, 25);
	}
	
}

void subState::MainMenu::deleteSource()
{
	deleteObject(menuWallpaper);
	deleteArrayObject(text);
	deleteObject(transparency);
	deleteObject(highlight);
	for (auto& object: menu)
	{
		deleteObject(object);
	}
	menu.clear();
}

subState::ExitMenu::ExitMenu(System& system, int* substate)
{
	transparency = nullptr;
	highlight = nullptr;
	audio = &system.getAudio();
	window = system.getHandle();
	keyboard = &system.getKeyboard();
	mouse = system.getMouse();
	titleFont = system.getTitleFont();
	normalFont = system.getNormalFont();
	answers = nullptr;
	text = nullptr;
	positionAnswersNow = 0;
	isPressed = false;
	this->substate = substate;
	sound.setVolume(audio->getEffectVolume());
}

void subState::ExitMenu::update()
{
	sf::Event event2;
	while (window->pollEvent(event2))
	{
		if (event2.type == sf::Event::Closed)
		{
			window->close();
		}
		if (event2.type == sf::Event::KeyPressed && !(isPressed))
		{
			isPressed = true;
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().left) || sf::Keyboard::isKeyPressed(keyboard->getConfig().right))
			{
				positionAnswersNow = positionAnswersNow == 0 ? 1 : 0;
			}
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().accept))
			{
				if (positionAnswersNow == 0)
				{
					playClickEffect();
					*substate = 0;
					break;
				}
				else
				{
					playClickEffect();
					*substate = 0;
					window->close();
					return;
				}
			}
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig().escape))
			{
				*substate = 0;
			}
		}
		if (event2.type == sf::Event::KeyReleased)
		{
			isPressed = false;
		}
		if (event2.type == sf::Event::MouseMoved)
		{
			sf::Vector2f cursor = mouse->getCoordinate();
			for (auto& object : exit)
			{
				if (object->containsCursor(cursor) && object->getStateColor() == 0)
				{
					positionAnswersNow = object->getState();
					break;
				}
			}
		}
		if (event2.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2f convert = mouse->getCoordinate();
			for (auto& object : exit)
			{
				if (object->containsCursor(convert))
				{
					if (positionAnswersNow == 0)
					{
						playClickEffect();
						*substate = 0;
					}
					else
					{
						playClickEffect();
						window->close();
						return;
					}
				}
			}
		}
	}
}

void subState::ExitMenu::render()
{
	exit[positionAnswersNow]->setHover();
	exit[abs(positionAnswersNow - 1)]->setIdle();
}

void subState::ExitMenu::draw()
{
	window->draw(exit[0]->getRect());
	window->draw(exit[1]->getRect());
	window->draw(text[0]);
	window->draw(text[1]);
	window->draw(text[2]);
}

void subState::ExitMenu::createSource()
{
	transparency = new sf::Texture;
	highlight = new sf::Texture;
	loadTexture("resources//Image//Textures//red.png", highlight);
	loadTexture("resources//Image//Textures//transparent.png", transparency);
	answers = new sf::String[2];
	answers[0] = "No";
	answers[1] = "Yes";
	text = new sf::Text[3];
	sf::Color white = sf::Color::White;
	setText("Are you sure you want to go back to your desktop?", text[2], titleFont, 540, 500, white, 40);
	for (int i = 0; i < 2; i++)
	{
		insertButton(i, exit, 600 + i * 50, 600, 40, 30, transparency, highlight);
		sf::Color white = sf::Color::White;
		setText(answers[i], text[i], normalFont, 600 + i * 50, 600, white, 25);
	}
}

void subState::ExitMenu::deleteSource()
{
	deleteObject(transparency);
	deleteObject(highlight);
	deleteArrayObject(answers);
	deleteArrayObject(text);
	for (auto& object : exit)
	{
		deleteObject(object);
	}
	exit.clear();
}


void subState::SubMenu::playClickEffect()
{
	sound.setBuffer(audio->getEffects("Click"));
	sound.play();
}

subState::SubMenu::SubMenu()
{
	transparency = nullptr;
	highlight = nullptr;
	titleFont = nullptr;
	normalFont = nullptr;
	window = nullptr;
	keyboard = nullptr;
	mouse = nullptr;
	audio = nullptr;
	substate = nullptr;
}

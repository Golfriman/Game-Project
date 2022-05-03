#include"Menu.h"

Menu::Menu(System& system, bool* isLoadSource)
{
	this->isLoadSource = isLoadSource;
	subMenu.resize(2);
	subMenu[0] = new subState::MainMenu(system, &substate, isLoadSource);
	subMenu[1] = new subState::ExitMenu(system, &substate, isLoadSource);
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
		object->removeSource();
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

subState::MainMenu::MainMenu(System& system, int* substate, bool* isLoadSource)
{
	this->isLoadSource = isLoadSource;
	audio = &system.getAudio();
	window = system.getHandle();
	keyboard = &system.getKeyboard();
	mouse = system.getMouse();
	titleFont = system.getTitleFont();
	normalFont = system.getNormalFont();
	transparency = nullptr;
	highlight = nullptr;
	menuWallpaper = nullptr;
	menuText = nullptr;
	last = { -1, -1 };
	isPressed = false;
	stateNow = 0;
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
			break;
		}
		if (event.type == sf::Event::KeyPressed && !(isPressed))
		{
			isPressed = true;
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig("Escape")))
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

			menu[stateNow]->setIdle();
			for (auto& object : menu)
			{
				if (object->containsCursor(convert) && object->getStateColor() == 0)
				{
					isHover = true;
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
						throw stateNow + ID_MENU + 1;
						break;
					}
				}
			}
		}
	}
}

void subState::MainMenu::render()
{
	if (isHover)
	{
		isHover = false;
		menu[stateNow]->setHover();
	}
}

void subState::MainMenu::draw()
{
	sf::Sprite wall(*menuWallpaper);
	window->draw(wall);
	for (int i = 0; i < 4; i++)
	{
		window->draw(menu[i]->getRect());
		window->draw(menuText[i]);
	}
}

void subState::MainMenu::createSource()
{
	transparency = new sf::Texture;
	highlight = new sf::Texture;
	loadTexture("resources//Image//Textures//red.png", highlight);
	loadTexture("resources//Image//Textures//transparent.png", transparency);
	menuWallpaper = new sf::Texture;
	loadTexture("resources//Image//Textures//menu.png", menuWallpaper);
	menuString[0] = L"Начать игру";
	menuString[1] = L"Настройки";
	menuString[2] = L"Журнал";
	menuString[3] = L"Выход";
	menuText = new sf::Text[4];
	sf::Color white = sf::Color::White;
	for (int i = 0; i < 4; i++)
	{
		insertButton(i, menu, 20, 700 + i * 35, 200, 30, transparency, highlight);
		setText(menuString[i], menuText[i], normalFont, 20, 700 + i * 35, white, 25);
	}
	*isLoadSource = true;
	
}

void subState::MainMenu::removeSource()
{
	deleteObject(menuWallpaper);
	deleteArrayObject(menuText);
	deleteObject(transparency);
	deleteObject(highlight);
	for (auto& object: menu)
	{
		deleteObject(object);
	}
	menu.clear();
}

subState::ExitMenu::ExitMenu(System& system, int* substate, bool* isLoadSource)
{
	this->isLoadSource = isLoadSource;
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
			break;
		}
		if (event2.type == sf::Event::KeyPressed && !(isPressed))
		{
			isPressed = true;
			if (sf::Keyboard::isKeyPressed(keyboard->getConfig("Escape")))
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
			exit[positionAnswersNow]->setIdle();
			for (auto& object : exit)
			{
				if (object->containsCursor(cursor) && object->getStateColor() == 0)
				{
					isHover = true;
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
	if (isHover)
	{
		isHover = false;
		exit[positionAnswersNow]->setHover();
	}
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
	answers[0] = L"Нет";
	answers[1] = L"Да";
	text = new sf::Text[3];
	sf::Color white = sf::Color::White;
	setText(L"Вы действительно хотите покинуть игру?", text[2], titleFont, 540, 500, white, 40);
	for (int i = 0; i < 2; i++)
	{
		insertButton(i, exit, 600 + i * 75, 600, 40, 30, transparency, highlight);
		sf::Color white = sf::Color::White;
		setText(answers[i], text[i], normalFont, 600 + i * 75, 600, white, 25);
	}
	*isLoadSource = true;
}

void subState::ExitMenu::removeSource()
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

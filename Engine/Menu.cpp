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
				sound.setVolume(audio->getEffectVolume());
				sound.setBuffer(audio->getEffects("Click"));
				*state = stateNow + 1;
				sound.play();
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
			Coordinate cursor{ convert.x, convert.y };
			if (menu[last] && menu[last]->getStateColor() == 1)
			{

				stateLast = menu[last]->getState();
			}
			if (menu[cursor] && menu[cursor]->getStateColor() == 0)
			{
				last = cursor;
				menu[menuPoint[stateNow]]->setIdle();
				stateNow = menu[cursor]->getState();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2f convert = mouse->getCoordinate();
				Coordinate cursor{ convert.x, convert.y };
				if (menu[cursor])
				{
					sound.setVolume(audio->getEffectVolume());
					sound.setBuffer(audio->getEffects("Click"));
					*state = stateNow + 1;
					sound.play();
				}
			}
		}
	}
}

void subState::MainMenu::render()
{
	menu[menuPoint[stateLast]]->setIdle();
	menu[menuPoint[stateNow]]->setHover();
}

void subState::MainMenu::draw()
{
	sf::Sprite wall(*menuWallpaper);
	window->draw(wall);
	for (int i = 0; i < 4; i++)
	{
		window->draw(menu[menuPoint[i]]->getRect());
		window->draw(*menu[menuPoint[i]]->getText());
	}
}

void subState::MainMenu::createSource()
{
	transparency = new sf::Color(sf::Color(0, 0, 0, 0));
	highlight = new sf::Color(sf::Color::Red);
	menuWallpaper = new sf::Texture;
	loadTexture("resources\\Image\\Textures\\tower2.jpg", menuWallpaper);
	text = new sf::String[4];
	text[0] = "New game";
	text[1] = "Settings";
	text[2] = "Journal";
	text[3] = "Exit";
	for (int i = 0; i < 4; i++)
	{
		insertButton(i, menu, menuPoint, 20, 700 + i * 35, 200, 30, 25, text[i], titleFont, sf::Color::White, transparency, highlight);
	}
	
}

void subState::MainMenu::deleteSource()
{
	deleteObject(menuWallpaper);
	deleteArrayObject(text);
	for (auto& coordinate : menuPoint)
	{
		deleteObject(menu[coordinate]);
	}
	menu.clear();
	menuPoint.clear();
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
	question = nullptr;
	positionAnswersNow = 0;
	isPressed = false;
	this->substate = substate;
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
					sound.setVolume(audio->getEffectVolume());
					sound.setBuffer(audio->getEffects("Click"));
					sound.play();
					*substate = 0;
				}
				else
				{
					sound.setVolume(audio->getEffectVolume());
					sound.setBuffer(audio->getEffects("Click"));
					sound.play();
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
			sf::Vector2f convert = mouse->getCoordinate();
			Coordinate cursor{ convert.x, convert.y };
			if (exit[cursor] && exit[cursor]->getStateColor() == 0)
			{
				positionAnswersNow = exit[cursor]->getState();
			}
		}
		if (event2.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2f convert = mouse->getCoordinate();
			Coordinate cursor{ convert.x, convert.y };
			if (exit[cursor])
			{
				if (positionAnswersNow == 0)
				{
					sound.setVolume(audio->getEffectVolume());
					sound.setBuffer(audio->getEffects("Click"));
					sound.play();
					*substate = 0;
				}
				else
				{
					sound.setVolume(audio->getEffectVolume());
					sound.setBuffer(audio->getEffects("Click"));
					sound.play();
					window->close();
					return;
				}
			}
		}
	}
}

void subState::ExitMenu::render()
{
	exit[exitPoint[positionAnswersNow]]->setHover();
	exit[exitPoint[abs(positionAnswersNow - 1)]]->setIdle();
}

void subState::ExitMenu::draw()
{
	window->draw(exit[exitPoint[0]]->getRect());
	window->draw(*exit[exitPoint[0]]->getText());
	window->draw(exit[exitPoint[1]]->getRect());
	window->draw(*exit[exitPoint[1]]->getText());
	window->draw(*question);
}

void subState::ExitMenu::createSource()
{
	transparency = new sf::Color(sf::Color(0, 0, 0, 0));
	highlight = new sf::Color(sf::Color::Red);
	answers = new sf::String[2];
	answers[0] = "No";
	answers[1] = "Yes";
	question = new sf::Text;
	sf::Color white = sf::Color::White;
	setText("Are you sure you want to go back to your desktop?", *question, *titleFont, 540, 500, white, 40);
	for (int i = 0; i < 2; i++)
	{
		insertButton(i, exit, exitPoint, 600 + i * 50, 600, 40, 30, 25, answers[i], normalFont, sf::Color::White, transparency, highlight);
	}
}

void subState::ExitMenu::deleteSource()
{
	deleteObject(transparency);
	deleteObject(highlight);
	deleteArrayObject(answers);
	deleteObject(question);
	for (auto& coordinate : exitPoint)
	{
		deleteObject(exit[coordinate]);
	}
	exit.clear();
	exitPoint.clear();
}

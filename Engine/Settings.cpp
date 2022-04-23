#include "Settings.h"
#include"../SaveAndLoad/Save.h"
#include"../SaveAndLoad/Load.h"

void Settings::playEffects()
{
	sound.setVolume(effectVolume);
	sound.play();
}

void Settings::createUI(sf::Color& white, sf::Color& red)
{
	setText(L"Настройки", text[0], titleFont, 863, 230, red, 64);
	setText(L"Video", text[1], normallFont, 466, 338, white, 36);
	setText(L"Fullscreen mode", text[2], normallFont, 476, 398, white, 24);
	loadTexture("resources//Image//Textures//switchOn.jpg", &textureButton[2]);
	loadTexture("resources//Image//Textures//switchOff.jpg", &textureButton[3]);
	insertButton(0, settingsButton, 767, 399, 28, 24, nullptr, nullptr, nullptr, &textureButton[2], &textureButton[3]);
	settingsButton[0]->setOnClick(switchFullscreen);
	setText(L"FPS", text[3], normallFont, 466, 443, white, 24);
	insertButton(1, settingsButton, 767, 443, 28, 24, nullptr, nullptr, nullptr, &textureButton[2], &textureButton[3]);
	settingsButton[1]->setOnClick(switchLimitFPS);
	setText(L"Разрешение экрана", text[4], normallFont, 466, 488, white, 24);
	loadTexture("resources//Image//Textures//Polygon 2.png", &textureButton[0]);
	insertButton(2, settingsButton, 714, 497, 18, 16, &textureButton[0]);
	settingsButton[2]->setOnClick(leftSize);
	loadTexture("resources//Image//Textures//Polygon 3.png", &textureButton[1]);
	insertButton(3, settingsButton, 862, 497, 18, 16, &textureButton[1]);
	settingsButton[3]->setOnClick(rightSize);
	setText(L"Горячие клавиши", text[5], normallFont, 466, 536, white, 36);

	setText(L"Пауза/Отмена", text[16], normallFont, 466, 596, white, 24);
	setText("Escape", text[17], normallFont, 779, 596, white, 24);
	setText(L"Инвентарь", text[18], normallFont, 466, 641, white, 24);
	setText("I", text[19], normallFont, 779, 641, white, 24);
	setText(L"Скрыть интерфейс", text[20], normallFont, 466, 686, white, 24);
	setText("H", text[21], normallFont, 779, 686, white, 24);
	setText(L"Аудио", text[22], normallFont, 953, 338, white, 36);
	setText(L"Фоновая музыка", text[23], normallFont, 953, 398, white, 24);
	insertButton(4, settingsButton, 1267, 405, 18, 16, &textureButton[0]);
	settingsButton[4]->setOnClick(leftBackgroundMusic);
	insertButton(5, settingsButton, 1333, 405, 18, 16, &textureButton[1]);
	settingsButton[5]->setOnClick(rightBackgroundMusic);
	setText(L"Эффекты", text[24], normallFont, 953, 443, white, 24);
	insertButton(6, settingsButton, 1267, 450, 18, 16, &textureButton[0]);
	settingsButton[6]->setOnClick(leftEffects);
	insertButton(7, settingsButton, 1333, 450, 18, 16, &textureButton[1]);
	settingsButton[7]->setOnClick(rightEffects);
	setText(L"Диалог", text[25], normallFont, 953, 488, white, 24);
	insertButton(8, settingsButton, 1267, 495, 18, 16, &textureButton[0]);
	settingsButton[8]->setOnClick(leftDialog);
	insertButton(9, settingsButton, 1333, 495, 18, 16, &textureButton[1]);
	settingsButton[9]->setOnClick(rightDialog);
	setText(L"Назад", text[26], normallFont, 492, 818, white, 24);
	loadTexture("resources//Image//Textures//Color(28,25,37).png", &textureButton[4]);
	insertButton(10, settingsButton, 432, 808, 187, 50, &textureButton[4]);
	settingsButton[10]->setOnClick(cancel);

	loadTexture("resources//Image//Textures//red.png", &textureButton[5]);
	insertButton(11, settingsButton, 1301, 808, 187, 50, &textureButton[5]);
	settingsButton[11]->setOnClick(applySettings);

	setText(L"Принять", text[28], normallFont, 1329, 818, white, 24);
	sf::String size = std::to_string(handle->getSize().x) + "x" + std::to_string(handle->getSize().y);
	setText(size, text[29], normallFont, 735, 488, white, 24);
	setText(std::to_string(backgroundVolume), text[30], normallFont, 1304, 398, white, 24);
	setText(std::to_string(effectVolume), text[31], normallFont, 1304, 443, white, 24);
	setText(std::to_string(dialogVolume), text[32], normallFont, 1304, 488, white, 24);
}

Settings::Settings(System& system, bool* isLoadSource, const int& id):id(id)
{
	this->isLoadSource = isLoadSource;
	wallpaper.setSize(sf::Vector2f(1088, 668));
	wallpaper.setFillColor(sf::Color(72, 111, 106));
	wallpaper.setPosition(416, 206);
	initSystemComponent(system);

	text = nullptr;
	sound.setVolume(audio->getEffectVolume());
	sound.setBuffer(audio->getEffects("Click"));
	switchFullscreen = [&]()->void
	{
		sf::Color white = sf::Color::White;
		system.getWindow().switchFullscreen();
		width = system.getHandle()->getSize().x;
		height = system.getHandle()->getSize().y;
		sf::String size = std::to_string(width) + "x" + std::to_string(height);
		setText(size, text[29], normallFont, 735 - size.getSize()*0.639f, 488, white, 24);
		isFullscreen = system.getWindow().isFull();
		sound.play();
		changeWindow = true;
	};
	switchLimitFPS = [&]()->void
	{
		system.getWindow().switchLimitFPS();
		isLimitFPS = system.getWindow().isLimit();
		sound.play();
		changeWindow = true;
	};
	leftSize = [&]()->void
	{
		sf::Color white = sf::Color::White;
		system.getWindow().leftChangeResolution();
		width = system.getHandle()->getSize().x;
		height = system.getHandle()->getSize().y;
		sf::String size = std::to_string(width) + "x" + std::to_string(height);
		setText(size, text[29], normallFont, 735, 488, white, 24);
		sound.play();
		changeWindow = true;
	};
	rightSize = [&]()->void
	{
		sf::Color white = sf::Color::White;
		system.getWindow().rightChangeResolution();
		width = system.getHandle()->getSize().x;
		height = system.getHandle()->getSize().y;
		sf::String size = std::to_string(width) + "x" + std::to_string(height);
		setText(size, text[29], normallFont, 735, 488, white, 24);
		sound.play();	
		changeWindow = true;
	};

	leftBackgroundMusic = [&]()->void
	{
		audio->left(audio->getBackgroundVolume());
		audio->setBackgroundVolume();
		sf::Color white = sf::Color::White;
		backgroundVolume = audio->getBackgroundVolume();
		sf::String volume = std::to_string(backgroundVolume);
		setText(volume, text[30], normallFont, 1304 - volume.getSize() * 5, 398, white, 24);
		sound.play();
	};
	rightBackgroundMusic = [&]()->void
	{
		audio->right(audio->getBackgroundVolume());
		audio->setBackgroundVolume();
		backgroundVolume = audio->getBackgroundVolume();
		sf::Color white = sf::Color::White;
		sf::String volume = std::to_string(backgroundVolume);
		setText(volume, text[30], normallFont, 1304 - volume.getSize()*5, 398, white, 24);
		sound.play();
	};
	leftEffects = [&]()
	{
		audio->left(audio->getEffectVolume());
		effectVolume = audio->getEffectVolume();
		sf::Color white = sf::Color::White;
		sf::String volume = std::to_string(effectVolume);
		setText(volume, text[31], normallFont, 1304 - volume.getSize()*5, 443, white, 24);
		playEffects();
	};
	rightEffects = [&]()->void
	{
		audio->right(audio->getEffectVolume());
		effectVolume = audio->getEffectVolume();
		sf::Color white = sf::Color::White;
		sf::String volume = std::to_string(effectVolume);
		setText(volume, text[31], normallFont, 1304 - volume.getSize()*5, 443, white, 24);
		playEffects();
	};
	leftDialog = [&]()
	{
		audio->left(audio->getDialogVolume());
		dialogVolume = audio->getDialogVolume();
		sf::Color white = sf::Color::White;
		sf::String volume = std::to_string(dialogVolume);
		setText(volume, text[32], normallFont, 1304 - volume.getSize()*5, 488, white, 24);
		sound.play();
	};
	rightDialog = [&]()->void
	{
		audio->right(audio->getDialogVolume());
		dialogVolume = audio->getDialogVolume();
		sf::Color white = sf::Color::White;
		sf::String volume = std::to_string(dialogVolume);
		setText(volume, text[32], normallFont, 1304 - volume.getSize() *5, 488, white, 24);
		sound.play();
	};

	applySettings = [&]()->void
	{
		Save saveSettings;

		saveSettings.addNote("BackgroundVolume", audio->getBackgroundVolume());
		saveSettings.addNote("Dialog", audio->getDialogVolume());
		saveSettings.addNote("Effects", audio->getEffectVolume());
		saveSettings.addNote("Fullscreen", window->isFull());
		saveSettings.addNote("LimitFPS", window->isLimit());
		saveSettings.addNote("IndexResolution", window->saveVar());
		saveSettings.saveFile();
		sound.play();
		changeWindow = false;
	};

	cancel = [&]()->void
	{
		LoadFile loadSettings;

		loadSettings.loadFile();
		loadSettings.outNote("BackgroundVolume", audio->getBackgroundVolume());
		loadSettings.outNote("Dialog", audio->getDialogVolume());
		loadSettings.outNote("Effects", audio->getEffectVolume());
		loadSettings.outNote("Fullscreen", window->isFull());
		loadSettings.outNote("LimitFPS", window->isLimit());
		loadSettings.outNote("IndexResolution", window->saveVar());
		if (changeWindow)
		{
			window->setWindow();
		}
		audio->setBackgroundVolume();
		playEffects();
		throw id;
	};
}

void Settings::createSource()
{
	isFullscreen = window->isFull();
	isLimitFPS= window->isLimit();

	width = handle->getSize().x;
	height = handle->getSize().y;
	backgroundVolume = audio->getBackgroundVolume();
	effectVolume = audio->getEffectVolume();
	dialogVolume = audio->getDialogVolume();
	changeWindow = false;

	text = new sf::Text[33];
	sf::Color white = sf::Color::White;
	sf::Color red = sf::Color(140, 25, 0);
	textureButton = new sf::Texture[6];
	createUI(white, red);
	*isLoadSource = true;
}

void Settings::removeSource()
{
	deleteArrayObject(text);
	deleteArrayObject(textureButton);
	for (auto& object : settingsButton)
	{
		deleteObject(object);
	}
	settingsButton.clear();
}

void Settings::update()
{

	while (handle->pollEvent(*event))
	{
		if (event->type == sf::Event::Closed)
		{
			handle->close();
			return;
		}
		if (event->type == sf::Event::KeyPressed)
		{
			if (event->key.code == keyboard->getConfig("Escape"))
			{
				throw 0;
			}
		}
		if (event->type == sf::Event::MouseButtonPressed)
		{
			if (event->key.code == sf::Mouse::Left)
			{
				sf::Vector2f cursor = mouse->getCoordinate();
				for (auto& object : settingsButton)
				{
					if (object->containsCursor(cursor))
					{
						object->startClick();
					}
				}
			}
		}
	}
}

void Settings::render()
{
	if (isFullscreen)
	{
		settingsButton[0]->setOn();
	}
	else
	{
		settingsButton[0]->setOff();
	}
	if (isLimitFPS)
	{
		settingsButton[1]->setOn();
	}
	else
	{
		settingsButton[1]->setOff();
	}
}

void Settings::draw()
{
	handle->draw(wallpaper);
	for (auto& object : settingsButton)
	{
		handle->draw(object->getRect());
	}
	for (int i = 0; i < 33; i++)
	{
		handle->draw(text[i]);
	}
}

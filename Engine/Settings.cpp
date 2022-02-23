#include "Settings.h"

void Settings::playEffects()
{
	sound.setVolume(effectVolume);
	sound.play();
}

Settings::Settings(System& system)
{
	wallpaper.setSize(sf::Vector2f(1088, 668));
	wallpaper.setFillColor(sf::Color(72, 111, 106));
	wallpaper.setPosition(416, 206);
	state = &system.getState();
	audio = &system.getAudio();
	handle = system.getHandle();
	keyboard = &system.getKeyboard();
	mouse = system.getMouse();
	titleFont = system.getTitleFont();
	normallFont = system.getNormalFont();
	isFullscreen = system.getWindow().isFull();
	isLimitFPS = system.getWindow().isLimit();
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
		setText(size, text[29], normallFont, 735, 488, white, 24);
		isFullscreen = system.getWindow().isFull();
		sound.play();
	};
	switchLimitFPS = [&]()->void
	{
		system.getWindow().switchLimitFPS();
		isLimitFPS = system.getWindow().isLimit();
		sound.play();
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
	};
	width = system.getHandle()->getSize().x;
	height = system.getHandle()->getSize().y;
	backgroundVolume = system.getAudio().getBackgroundVolume();
	effectVolume = system.getAudio().getEffectVolume();
	dialogVolume = system.getAudio().getDialogVolume();
	leftBackgroundMusic = [&]()->void
	{
		audio->left(audio->getBackgroundVolume());
		audio->setBackgroundVolume();
		sf::Color white = sf::Color::White;
		backgroundVolume = audio->getBackgroundVolume();
		setText(std::to_string(backgroundVolume), text[30], normallFont, 1304, 398, white, 24);
		sound.play();
	};
	rightBackgroundMusic = [&]()->void
	{
		audio->right(audio->getBackgroundVolume());
		audio->setBackgroundVolume();
		backgroundVolume = audio->getBackgroundVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(backgroundVolume), text[30], normallFont, 1304, 398, white, 24);
		sound.play();
	};
	leftEffects = [&]()
	{
		audio->left(audio->getEffectVolume());
		effectVolume = audio->getEffectVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(effectVolume), text[31], normallFont, 1304, 443, white, 24);
		playEffects();
	};
	rightEffects = [&]()->void
	{
		audio->right(audio->getEffectVolume());
		effectVolume = audio->getEffectVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(effectVolume), text[31], normallFont, 1304, 443, white, 24);
		playEffects();
	};
	leftDialog = [&]()
	{
		audio->left(audio->getDialogVolume());
		dialogVolume = audio->getDialogVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(dialogVolume), text[32], normallFont, 1304, 488, white, 24);
		sound.play();
	};
	rightDialog = [&]()->void
	{
		audio->right(audio->getDialogVolume());
		dialogVolume = audio->getDialogVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(dialogVolume), text[32], normallFont, 1304, 488, white, 24);
		sound.play();
	};
	cancel = [&]()->void
	{
		*state = 0;
		sound.play();
	};
	lastState = 0;
	nowState = 0;
}

void Settings::createSource()
{
	text = new sf::Text[33];
	sf::Color white = sf::Color::White;
	sf::Color red = sf::Color(140, 25, 0);
	texture = new sf::Texture[5];
	setText("Settings", text[0], titleFont, 863, 230, red, 64);
	setText("Video", text[1], normallFont, 476, 338, white, 36);
	setText("Fullscreen mode",text[2], normallFont, 476, 398, white, 24);
	loadTexture("resources//Image//Textures//switchOn.jpg", &texture[2]);
	loadTexture("resources//Image//Textures//switchOff.jpg", &texture[3]);
	insertButton(0, settingsButton,767, 399, 28, 24, nullptr, nullptr, nullptr, &texture[2], &texture[3]);
	settingsButton[0]->setOnClick(switchFullscreen);
	setText("Limit FPS", text[3], normallFont, 476, 443, white, 24);
	insertButton(1, settingsButton, 767, 443, 28, 24,nullptr, nullptr, nullptr, &texture[2], &texture[3]);
	settingsButton[1]->setOnClick(switchLimitFPS);
	setText("Screen resolution", text[4], normallFont, 476, 488, white, 24);
	loadTexture("resources//Image//Textures//Polygon 2.png", &texture[0]);
	insertButton(2, settingsButton, 714, 497, 18, 16, &texture[0]);
	settingsButton[2]->setOnClick(leftSize);
	loadTexture("resources//Image//Textures//Polygon 3.png", &texture[1]);
	insertButton(3, settingsButton, 862, 497, 18, 16, &texture[1]);
	settingsButton[3]->setOnClick(rightSize);
	setText("Keyboard shortcut", text[5], normallFont, 476, 536, white, 36);
	setText("Right", text[6], normallFont, 476, 596, white, 24);
	setText("D", text[7], normallFont, 779, 596, white, 24);
	setText("Left", text[8], normallFont, 476, 641, white, 24);
	setText("A", text[9], normallFont, 779, 641, white, 24);
	setText("Down", text[10], normallFont, 476, 686, white, 24);
	setText("S", text[11], normallFont, 779, 686, white, 24);
	setText("Up", text[12], normallFont, 476, 731, white, 24);
	setText("W", text[13], normallFont, 779, 731, white, 24);
	setText("Accept", text[14], normallFont, 953, 596, white, 24);
	setText("Enter", text[15], normallFont, 1267, 596, white, 24);
	setText("Cancel", text[16], normallFont, 953, 641, white, 24);
	setText("Escape", text[17], normallFont, 1267, 641, white, 24);
	setText("Inventory", text[18], normallFont, 953, 686, white, 24);
	setText("I", text[19], normallFont, 1267, 686, white, 24);
	setText("Hide HUD", text[20], normallFont, 953, 731, white, 24);
	setText("H", text[21], normallFont, 1267, 731, white, 24);
	setText("Audio", text[22], normallFont, 953, 338, white, 36);
	setText("Background Music", text[23], normallFont, 953, 398, white, 24);
	insertButton(4, settingsButton, 1267, 405, 18, 16, &texture[0]);
	settingsButton[4]->setOnClick(leftBackgroundMusic);
	insertButton(5, settingsButton, 1333, 405, 18, 16, &texture[1]);
	settingsButton[5]->setOnClick(rightBackgroundMusic);
	setText("Effects", text[24], normallFont, 953, 443, white, 24);
	insertButton(6, settingsButton, 1267, 450, 18, 16, &texture[0]);
	settingsButton[6]->setOnClick(leftEffects);
	insertButton(7, settingsButton, 1333, 450, 18, 16, &texture[1]);
	settingsButton[7]->setOnClick(rightEffects);
	setText("Dialog", text[25], normallFont, 953, 488, white, 24);
	insertButton(8, settingsButton, 1267, 495, 18, 16, &texture[0]);
	settingsButton[8]->setOnClick(leftDialog);
	insertButton(9, settingsButton, 1333, 495, 18, 16, &texture[1]);
	settingsButton[9]->setOnClick(rightDialog);
	setText("Back", text[26], normallFont, 492, 818, white, 24);
	sf::Color buttonBack = sf::Color(28, 25, 37);
	loadTexture("resources//Image//Textures//Color(28,25,37).png", &texture[4]);
	insertButton(10, settingsButton, 432, 808, 157, 98, &texture[4]);
	settingsButton[10]->setOnClick(cancel);
	setText("Default", text[27], normallFont, 1130, 818, white, 24);
	setText("Apply", text[28], normallFont, 1360, 818, white, 24);
	sf::String size = std::to_string(handle->getSize().x) + "x" + std::to_string(handle->getSize().y);
	setText(size, text[29], normallFont, 735, 488, white, 24);
	setText(std::to_string(backgroundVolume), text[30], normallFont, 1304, 398, white, 24);
	setText(std::to_string(effectVolume), text[31], normallFont, 1304, 443, white, 24);
	setText(std::to_string(dialogVolume), text[32], normallFont, 1304, 488, white, 24);


}

void Settings::removeSource()
{
	deleteArrayObject(text);
	for (auto& object : settingsButton)
	{
		deleteObject(object);
	}
	settingsButton.clear();
	deleteArrayObject(texture);
}

void Settings::update()
{
	sf::Event event;
	while (handle->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			handle->close();
			return;
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == keyboard->getConfig().down)
			{
				lastState = nowState;
				nowState = nowState + 1 >= 10 ? 0 : nowState + 1;
			}
			if (event.key.code == keyboard->getConfig().up)
			{
				lastState = nowState;
				nowState = nowState - 1 < 0 ? 10 : nowState - 1;
			}
			if (event.key.code == keyboard->getConfig().accept)
			{
				settingsButton[nowState]->startClick();
			}
			if (event.key.code == keyboard->getConfig().escape)
			{
				*state = 0;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
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

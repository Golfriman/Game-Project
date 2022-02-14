#include "Settings.h"

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
	text = nullptr;
	transparency = nullptr;
	highlight = nullptr;
	sound.setVolume(audio->getEffectVolume());
	sound.setBuffer(audio->getEffects("Click"));
	switchFullscreen = [&]()->void
	{
		sf::Color white = sf::Color::White;
		system.getWindow().switchFullscreen();
		width = system.getHandle()->getSize().x;
		height = system.getHandle()->getSize().y;
		sf::String size = std::to_string(width) + "x" + std::to_string(height);
		setText(size, text[29], *normallFont, 735, 488, white, 24);
		sound.play();
	};
	switchLimitFPS = [&]()->void
	{
		system.getWindow().switchLimitFPS();
		sound.play();
	};
	leftSize = [&]()->void
	{
		sf::Color white = sf::Color::White;
		system.getWindow().leftChangeResolution();
		width = system.getHandle()->getSize().x;
		height = system.getHandle()->getSize().y;
		sf::String size = std::to_string(width) + "x" + std::to_string(height);
		setText(size, text[29], *normallFont, 735, 488, white, 24);
		sound.play();
	};
	rightSize = [&]()->void
	{
		sf::Color white = sf::Color::White;
		system.getWindow().rightChangeResolution();
		width = system.getHandle()->getSize().x;
		height = system.getHandle()->getSize().y;
		sf::String size = std::to_string(width) + "x" + std::to_string(height);
		setText(size, text[29], *normallFont, 735, 488, white, 24);
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
		setText(std::to_string(backgroundVolume), text[30], *normallFont, 1304, 398, white, 24);
		sound.play();
	};
	rightBackgroundMusic = [&]()->void
	{
		audio->right(audio->getBackgroundVolume());
		audio->setBackgroundVolume();
		backgroundVolume = audio->getBackgroundVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(backgroundVolume), text[30], *normallFont, 1304, 398, white, 24);
		sound.play();
	};
	leftEffects = [&]()
	{
		audio->left(audio->getEffectVolume());
		effectVolume = audio->getEffectVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(effectVolume), text[31], *normallFont, 1304, 443, white, 24);
		sound.setVolume(effectVolume);
		sound.play();
	};
	rightEffects = [&]()->void
	{
		audio->right(audio->getEffectVolume());
		effectVolume = audio->getEffectVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(effectVolume), text[31], *normallFont, 1304, 443, white, 24);
		sound.setVolume(effectVolume);
		sound.play();
	};
	leftDialog = [&]()
	{
		audio->left(audio->getDialogVolume());
		dialogVolume = audio->getDialogVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(dialogVolume), text[32], *normallFont, 1304, 488, white, 24);
		sound.play();
	};
	rightDialog = [&]()->void
	{
		audio->right(audio->getDialogVolume());
		dialogVolume = audio->getDialogVolume();
		sf::Color white = sf::Color::White;
		setText(std::to_string(dialogVolume), text[32], *normallFont, 1304, 488, white, 24);
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
	transparency = new sf::Color(sf::Color(0, 0, 0, 0));
	highlight = new sf::Color(sf::Color(255, 0, 0, 255));
	text = new sf::Text[33];
	sf::Color white = sf::Color::White;
	sf::Color red = sf::Color(140, 25, 0);
	setText("Settings", text[0], *titleFont, 863, 230, red, 64);
	setText("Video", text[1], *normallFont, 476, 338, white, 36);
	setText("Fullscreen mode",text[2], *normallFont, 476, 398, white, 24);
	insertButton(0, settingsButton, settingsButtonPoint, 767, 399, 27, 22, 0, "\0", nullptr, sf::Color::Black, &white);
	settingsButton[settingsButtonPoint[0]]->setOnClick(&switchFullscreen);
	setText("Limit FPS", text[3], *normallFont, 476, 443, white, 24);
	insertButton(1, settingsButton, settingsButtonPoint, 767, 443, 27, 22, 0, "\0", nullptr, sf::Color::Black, &white);
	settingsButton[settingsButtonPoint[1]]->setOnClick(&switchLimitFPS);
	setText("Screen resolution", text[4], *normallFont, 476, 488, white, 24);
	texture = new sf::Texture[2];
	loadTexture("resources\\Image\\Textures\\Polygon 2.png", &texture[0]);
	insertButton(2, settingsButton, settingsButtonPoint, 714, 493, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr,&texture[0]);
	settingsButton[settingsButtonPoint[2]]->setOnClick(&leftSize);
	loadTexture("resources\\Image\\Textures\\Polygon 3.png", &texture[1]);
	insertButton(3, settingsButton, settingsButtonPoint, 862, 493, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[1]);
	settingsButton[settingsButtonPoint[3]]->setOnClick(&rightSize);
	setText("Keyboard shortcut", text[5], *normallFont, 476, 536, white, 36);
	setText("Right", text[6], *normallFont, 476, 596, white, 24);
	setText("D", text[7], *normallFont, 779, 596, white, 24);
	setText("Left", text[8], *normallFont, 476, 641, white, 24);
	setText("A", text[9], *normallFont, 779, 641, white, 24);
	setText("Down", text[10], *normallFont, 476, 686, white, 24);
	setText("S", text[11], *normallFont, 779, 686, white, 24);
	setText("Up", text[12], *normallFont, 476, 731, white, 24);
	setText("W", text[13], *normallFont, 779, 731, white, 24);
	setText("Accept", text[14], *normallFont, 953, 596, white, 24);
	setText("Enter", text[15], *normallFont, 1267, 596, white, 24);
	setText("Cancel", text[16], *normallFont, 953, 641, white, 24);
	setText("Escape", text[17], *normallFont, 1267, 641, white, 24);
	setText("Inventory", text[18], *normallFont, 953, 686, white, 24);
	setText("I", text[19], *normallFont, 1267, 686, white, 24);
	setText("Hide HUD", text[20], *normallFont, 953, 731, white, 24);
	setText("H", text[21], *normallFont, 1267, 731, white, 24);
	setText("Audio", text[22], *normallFont, 953, 338, white, 36);
	setText("Background Music", text[23], *normallFont, 953, 398, white, 24);
	insertButton(4, settingsButton, settingsButtonPoint, 1267, 398, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[0]);
	settingsButton[settingsButtonPoint[4]]->setOnClick(&leftBackgroundMusic);
	insertButton(5, settingsButton, settingsButtonPoint, 1333, 398, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[1]);
	settingsButton[settingsButtonPoint[5]]->setOnClick(&rightBackgroundMusic);
	setText("Effects", text[24], *normallFont, 953, 443, white, 24);
	insertButton(6, settingsButton, settingsButtonPoint, 1267, 443, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[0]);
	settingsButton[settingsButtonPoint[6]]->setOnClick(&leftEffects);
	insertButton(7, settingsButton, settingsButtonPoint, 1333, 443, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[1]);
	settingsButton[settingsButtonPoint[7]]->setOnClick(&rightEffects);
	setText("Dialog", text[25], *normallFont, 953, 488, white, 24);
	insertButton(8, settingsButton, settingsButtonPoint, 1267, 488, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[0]);
	settingsButton[settingsButtonPoint[8]]->setOnClick(&leftDialog);
	insertButton(9, settingsButton, settingsButtonPoint, 1333, 488, 18, 16, 0, "\0", nullptr, sf::Color::Black, nullptr, nullptr, nullptr, nullptr, nullptr, &texture[1]);
	settingsButton[settingsButtonPoint[9]]->setOnClick(&rightDialog);
	setText("Back", text[26], *normallFont, 492, 818, white, 24);
	sf::Color buttonBack = sf::Color(28, 25, 37);
	insertButton(10, settingsButton, settingsButtonPoint, 432, 808, 187, 50, 0, "\0", nullptr, sf::Color::Black, &buttonBack, nullptr, nullptr, nullptr, nullptr);
	settingsButton[settingsButtonPoint[10]]->setOnClick(&cancel);
	setText("Default", text[27], *normallFont, 1130, 818, white, 24);
	setText("Apply", text[28], *normallFont, 1360, 818, white, 24);
	sf::String size = std::to_string(handle->getSize().x) + "x" + std::to_string(handle->getSize().y);
	setText(size, text[29], *normallFont, 735, 488, white, 24);
	setText(std::to_string(backgroundVolume), text[30], *normallFont, 1304, 398, white, 24);
	setText(std::to_string(effectVolume), text[31], *normallFont, 1304, 443, white, 24);
	setText(std::to_string(dialogVolume), text[32], *normallFont, 1304, 488, white, 24);


}

void Settings::removeSource()
{
	deleteArrayObject(text);
	for (auto& coordinate : settingsButtonPoint)
	{
		deleteObject(settingsButton[coordinate]);
	}
	settingsButton.clear();
	settingsButtonPoint.clear();
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
				nowState = nowState + 1 >= 5 ? 0 : nowState + 1;
			}
			if (event.key.code == keyboard->getConfig().up)
			{
				lastState = nowState;
				nowState = nowState - 1 < 0 ? 4 : nowState - 1;
			}
			if (event.key.code == keyboard->getConfig().accept)
			{
				settingsButton[settingsButtonPoint[nowState]]->startClick();
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
				sf::Vector2f convert = mouse->getCoordinate();
				Coordinate cursor{ convert.x, convert.y };
				if (settingsButton[cursor])
				{
					settingsButton[cursor]->startClick();
				}
			}
		}
	}
}

void Settings::render()
{

}

void Settings::draw()
{
	handle->draw(wallpaper);
	for (auto& coordinate : settingsButtonPoint)
	{
		handle->draw(settingsButton[coordinate]->getRect());
		if (settingsButton[coordinate]->getText())
		{
			handle->draw(*settingsButton[coordinate]->getText());
		}
	}
	for (int i = 0; i < 33; i++)
	{
		handle->draw(text[i]);
	}
}

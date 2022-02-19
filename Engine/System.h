#pragma once

#include"Audio/Audio.h"
#include"Keyboard/Keyboard.h"
#include"Window/Window.h"
#include"Mouse/Mouse.h"


class System
{
	Window window;
	Audio audio;
	Keyboard keyboard;
	Mouse* mouse;
	int state;
	sf::Font* titleFont;
	sf::Font* normalFont;

public:
	System(/*Log file*/);
	
	sf::RenderWindow* getHandle();
	Window& getWindow();
	Audio& getAudio();
	Keyboard& getKeyboard();
	Mouse* getMouse();
	int& getState();
	sf::Font* getTitleFont();
	sf::Font* getNormalFont();
	~System();
};
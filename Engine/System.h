#pragma once

#include"Audio/Audio.h"
#include"Keyboard/Keyboard.h"
#include"Window/Window.h"
#include"Mouse/Mouse.h"
#include"Global/Support function.h"


class System
{
	/*Класс сохранения*/

	Window window;
	Audio audio;
	Keyboard keyboard;
	Mouse* mouse;
	sf::Font* titleFont;
	sf::Font* normalFont;
	sf::Event* event;
public:

	System();
	
	sf::RenderWindow* getHandle();
	Window& getWindow();
	Audio& getAudio();
	Keyboard& getKeyboard();
	Mouse* getMouse();
	sf::Font* getTitleFont();
	sf::Font* getNormalFont();
	sf::Event* getEvent();
	~System();
};
#pragma once
#include"Menu.h"
#include"Game.h"
#include"Settings.h"
#include"Journal.h"
#include"Exit.h"

class Engine
{
	int stateEngine;
	std::unordered_map<int,State*> stateGame;
	System* system;
	sf::RenderWindow* window;
	bool isLoadSource;
	sf::Texture t_loadScreen;
	sf::RectangleShape wallpaperScreen;
public:
	Engine();
	void update();
	void render();
	void draw();
	bool windowIsOpen();
	~Engine();
	void showLoadScreen();
};
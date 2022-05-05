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
public:
	Engine();
	void update();
	void render();
	void draw();
	bool windowIsOpen();
	~Engine();
	void showLoadScreen();
};
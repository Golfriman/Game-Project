#pragma once
#include"Menu.h"
#include"Game.h"
#include"Settings.h"
#include"Journal.h"
#include"Exit.h"
#include<unordered_map>
#include<thread>

class Engine
{
	int stateEngine;
	std::vector<State*> stateGame;
	System system;
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
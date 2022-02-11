#pragma once
#include"Menu.h"
#include"Game.h"
#include"Settings.h"
#include"Journal.h"
#include"Exit.h"
#include<unordered_map>

class Engine
{
	int *state;
	int stateEngine;
	std::vector<State*> stateGame;
	System system;
	sf::RenderWindow* window;
public:
	Engine();
	void update();
	void render();
	void draw();
	bool windowIsOpen();
	~Engine();
};
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
	static constexpr int ID_MENU = 0;
	static constexpr int ID_GAME = 1;
	static constexpr int ID_SETTINGS = 2;
	static constexpr int ID_JOURNAL = 3;
	static constexpr int ID_EXIT = 4;

	int stateEngine;
	std::vector<State*> stateGame;
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
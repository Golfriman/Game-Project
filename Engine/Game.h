#pragma once
#include"State.h"
#include"./Game/Tower state/Battle.h"
#include"./Game/Tower state/RandomEvent.h"
#include"Game/Tower state/Blacksmith.h"

#include"./Game/Hero.h"
#include<random>
#include<ranges>
#include<algorithm>`

class Game : public State
{
	std::vector<TowerState*> towerstates;
	size_t idGame;

	Hero* hero;
	bool showHUD;
	std::mt19937* mersenne;
	System* system;
	void generateLevel(System& system);
public:
	Game(System& system, bool* isLoadSource);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
	~Game();
};

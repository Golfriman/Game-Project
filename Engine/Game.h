#pragma once
#include"State.h"
#include"./Game/Tower state/TowerState.h"

class Game : public State
{
	std::vector<TowerState*> towerstates;
	size_t *idTowerStates;
	size_t idGame;
public:
	Game(System& system, bool* isLoadSource);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};

#pragma once
#include"TowerState.h"
#include"Enimies/Enimies.h"
#include<vector>

class Battle: public TowerState
{
	std::vector<Enimies*> enimiesInTheRoom;
public:
	Battle(System& system);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~Battle();
};
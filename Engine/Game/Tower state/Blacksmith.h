#pragma once
#include"TowerState.h"
#include<vector>

class BlacksmithEvent;

class BlackSmith : public TowerState
{
	std::vector<BlacksmithEvent*> bEvents;
	size_t stateBlack;
public:
	BlackSmith(System& system, Hero* hero, bool* isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~BlackSmith();
};

#pragma once
#include"TowerState.h"
#include<vector>
#include"BlacksmithEvent/BlacksmithEvent.h"

class BlackSmith : public TowerState
{
	std::vector<BlacksmithEvent*> events;
public:
	BlackSmith(System& system, Hero* hero);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~BlackSmith();
};

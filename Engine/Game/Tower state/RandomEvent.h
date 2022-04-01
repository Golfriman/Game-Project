#pragma once
#include"TowerState.h"

class RandomEvent : public TowerState
{
public:
	RandomEvent(System& system);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~RandomEvent();
};
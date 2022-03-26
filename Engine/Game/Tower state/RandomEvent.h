#pragma once
#include"TowerState.h"

class RandomEvent : public TowerState
{
public:
	void update();
	void render();
	void draw();
	void createSource();
	void removeSource();
	~RandomEvent();
};
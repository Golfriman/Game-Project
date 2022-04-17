#pragma once

#include"BlacksmithEvent.h"

class Farewell : public BlacksmithEvent
{
public:
	Farewell(System& system, Hero* hero, bool* isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};
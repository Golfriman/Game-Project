#pragma once
#include"BlacksmithEvent.h"

class Dialog : public BlacksmithEvent
{
public:
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};

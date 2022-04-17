#pragma once
#include"BlacksmithEvent.h"

class Dialog : public BlacksmithEvent
{
public:
	Dialog(System& system, Hero* hero, bool* isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};

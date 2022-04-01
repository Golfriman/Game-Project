#pragma once

#include"BlacksmithEvent.h"

class UpgradeWeapon : public BlacksmithEvent
{
public:

	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};

#pragma once

#include"BlacksmithEvent.h"

class UpgradeWeapon : public BlacksmithEvent
{
public:
	UpgradeWeapon(System& system, Hero* hero, bool* isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};

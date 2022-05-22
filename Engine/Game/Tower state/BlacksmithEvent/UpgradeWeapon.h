#pragma once

#include"BlacksmithEvent.h"

class UpgradeWeapon : public BlacksmithEvent
{
	std::vector <Button*> menuButton;
	void createUI();
	bool hoverButton;
	size_t idHoverButton;
	sf::Texture* textureButton;
	sf::Color* white;
public:
	UpgradeWeapon(System& system, Hero* hero, bool* isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};

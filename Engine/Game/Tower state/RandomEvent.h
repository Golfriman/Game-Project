#pragma once
#include"TowerState.h"

class RandomEvent : public TowerState
{
	std::vector<Button*> buttons;
	sf::Texture* texture;
	sf::Text* text;
public:
	RandomEvent(System& system, Hero* hero, bool *isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~RandomEvent();
};
#pragma once
#include"TowerState.h"

class RandomEvent : public TowerState
{
	sf::Color white;
	std::vector<Button*> buttons;
	sf::Texture* texture;
	std::vector<sf::Text> text;
	void createAltarEvent();
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
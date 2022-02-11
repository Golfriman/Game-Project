#pragma once
#include"State.h"

class Exit : public State
{
	sf::RenderWindow* window;
public:
	Exit(System& system);
	void removeSource()override;
	void createSource()override;
	void update();
	void render();
	void draw();
};
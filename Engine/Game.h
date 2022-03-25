#pragma once
#include"State.h"

class Game : public State
{
	int* state;
	sf::Text* text;
	sf::Color *white;
public:
	Game(System& system, bool* isLoadSource);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};

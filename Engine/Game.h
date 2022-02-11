#pragma once
#include"State.h"

class Game : public State
{
	int* state;
	sf::Font* font;
	sf::Text* text;
	sf::Color *white;
	sf::RenderWindow* window;
	Keyboard* keyboard;
public:
	Game(System& system);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};

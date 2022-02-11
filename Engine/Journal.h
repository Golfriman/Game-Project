#pragma once
#include"State.h"

class Journal : public State
{
	sf::Color* white;
	sf::Font* font;
	sf::Text* text;
	sf::RenderWindow *window;
	int* state;
	Keyboard* keyboard;
public:
	Journal(System& system);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};
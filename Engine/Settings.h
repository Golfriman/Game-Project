#pragma once
#include"State.h"

class Settings : public State
{
	int* state;
	sf::Color *white;
	sf::Font* font;
	sf::Text* text;
	Window *window;
	Audio *audio;
	Keyboard *keyboard;
	sf::RenderWindow* handle;
public:
	Settings(System& system);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};
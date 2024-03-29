#pragma once
#include"Global/Support function.h"
#include"System.h"

class State
{
protected:
	sf::Event* event;
	Window* window;
	Audio* audio;
	Keyboard* keyboard;
	Mouse* mouse;
	sf::RenderWindow* handle;
	sf::Font* titleFont;
	sf::Font* normallFont;
	bool* isLoadSource;
	void initSystemComponent(System& system);
public:
	State();
	virtual void createSource() = 0;
	virtual void removeSource() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual ~State() = default;
};

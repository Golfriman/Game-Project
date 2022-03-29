#pragma once
#include"../../System.h"
#include"../../Global/Button.h"
#include"../../Global/Support function.h"

class TowerState
{
protected:
	int* state;
	sf::Texture* wallpaper;
	sf::RenderWindow* handle;
	Audio* audio;
	Keyboard* keyboard;
	Mouse* mouse;
	sf::Font* titleFont;
	sf::Font* normallFont;
	void initSystemComponent(System& system);
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual void createSource() = 0;
	virtual void removeSource() = 0;
	virtual ~TowerState() = default;
};
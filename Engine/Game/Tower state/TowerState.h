#pragma once
#include"../../System.h"
#include"../../Global/Button.h"
#include"../../Global/Support function.h"
#include"../Hero.h"

class TowerState
{
protected:
	bool* isLoadSource;
	sf::Event* event;
	Hero* hero;
	sf::Texture* wallpaper;
	sf::RenderWindow* handle;
	Audio* audio;
	Keyboard* keyboard;
	Mouse* mouse;
	sf::Font* titleFont;
	sf::Font* normallFont;
	void init(System& system, Hero* hero, bool*isLoadSource);
public:
	TowerState();
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual void createSource() = 0;
	virtual void removeSource() = 0;
	virtual void hud() = 0;
	virtual ~TowerState() = default;
};
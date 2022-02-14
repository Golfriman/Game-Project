#pragma once
#include"State.h"
#include<string>

class Settings : public State
{
	int* state;
	int lastState, nowState;
	sf::Color* transparency, * highlight;
	sf::Font* titleFont;
	sf::Font* normallFont;
	sf::Text* text;
	Window* window;
	Audio* audio;
	Keyboard* keyboard;
	Mouse* mouse;
	sf::RenderWindow* handle;
	sf::Sound sound;
	std::unordered_map<Coordinate, Button*> settingsButton;
	std::vector<Coordinate> settingsButtonPoint;

	std::function<void()> switchFullscreen;
	std::function<void()> leftSize;
	std::function<void()> rightSize;
	std::function<void()> switchLimitFPS;
	std::function<void()> leftBackgroundMusic;
	std::function<void()> rightBackgroundMusic;
	std::function<void()> leftEffects;
	std::function<void()> rightEffects;
	std::function<void()> leftDialog;
	std::function<void()> rightDialog;
	
	std::function<void()> cancel;
	sf::RectangleShape wallpaper;
	int width = 0;
	int height = 0;
	int backgroundVolume;
	int effectVolume;
	int dialogVolume;
	sf::Texture* texture;
public:
	Settings(System& system);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};
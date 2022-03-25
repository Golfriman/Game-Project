#pragma once
#include"State.h"
#include<string>

class Settings : public State
{
	int* state;
	int lastState, nowState;
	sf::Text* text;
	sf::Sound sound;
	std::vector<Button*> settingsButton;

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
	bool isFullscreen, isLimitFPS;
	void playEffects();
public:
	Settings(System& system, bool* isLoadSource);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};
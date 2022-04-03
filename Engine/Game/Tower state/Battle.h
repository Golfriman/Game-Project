#pragma once
#include"TowerState.h"
#include"Enimies/Enimies.h"
#include<vector>

class Battle: public TowerState
{
	bool isDelete;
	bool turnPlayer;
	std::vector<Enimies*> enimiesInTheRoom;
	std::vector<Button*> buttons;
	sf::Texture* texture;
	sf::Text* text;
	sf::Color* white;
	std::vector<sf::RectangleShape*> healthBar;
	std::vector<sf::RectangleShape*> maxHealth;
	sf::Sprite wall;
	void createUI();
public:
	Battle(System& system, Hero* hero);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~Battle();
};
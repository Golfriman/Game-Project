#pragma once
#include"../../Hero.h"
#include"../../Items/Items.h"
#include<any>

class Enimies: public Unit
{
protected:
	sf::Texture text;
	Items* items;
	void dropItem();
public:
	Enimies(float x, float y, sf::String path);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	bool makeADecision(Hero* hero);
	void attackWithASpecialAttack(Unit* unit);
	void execute();
	Items* kill();
};

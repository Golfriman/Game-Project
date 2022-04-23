#pragma once
#include"../../Hero.h"
#include"../../Items/Items.h"

class Enimies: public Unit
{
protected:
	sf::Texture text;
	Items* items;
	void dropItem();
public:
	Enimies(float x, float y, sf::String path);
	bool makeADecision(Hero* hero);
	void attackWithASpecialAttack(Unit* unit);
	void execute();
	Items* kill();
};

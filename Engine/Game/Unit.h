#pragma once
#include"Characteristics.h"
#include<SFML/Graphics.hpp>

class Unit: public sf::Drawable
{
protected:
	bool block;
	Characteristics* characterisitcs;
	sf::RectangleShape* spriteUnit;
	uint8_t stateAnimationSprite;
	bool show;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
public:
	uint8_t getNumberOfAction();
	void setBlock();
	Unit();
	void updateSprite();
	void updateStateAnimation();
	void showHealthBar(bool show);
	void attackWithALightAttack(Unit* unit);
	void attackWithAHeavyAttack(Unit* unit);
	virtual void attackWithASpecialAttack(Unit* unit) = 0;
	Characteristics* getCharacteristics();
	bool isDead() const;
	virtual ~Unit();
};

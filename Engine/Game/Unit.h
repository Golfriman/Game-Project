#pragma once
#include"Characteristics.h"
#include<SFML/Graphics.hpp>
class Unit
{
protected:
	Characteristics* characterisitcs;
	sf::Sprite* sprite;
	uint8_t stateAnimationSprite;
public:
	virtual void execute() = 0;
	void updateSprite();
	void updateStateAnimation();
	Characteristics* getCharacteristics();
	bool isDead();
	virtual ~Unit() = default;
};

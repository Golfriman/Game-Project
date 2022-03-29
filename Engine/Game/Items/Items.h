#pragma once
#include<SFML/Graphics.hpp>
#include"../Unit.h"

class Items: public sf::Drawable
{
protected:
	sf::Texture* textureItem;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	virtual void use(Unit* unit) = 0;
	virtual void show() = 0;
};
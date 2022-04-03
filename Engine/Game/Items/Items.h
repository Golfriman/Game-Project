#pragma once
#include<SFML/Graphics.hpp>
#include"../Unit.h"

class Items: public sf::Drawable
{
protected:
	sf::Texture* textureItem;
	sf::String info;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	virtual void use(Unit* unit) = 0;
	//„тобы текст был на новой строчке пишем \n
	virtual sf::String show() = 0;
};
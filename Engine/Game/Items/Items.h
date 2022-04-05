#pragma once
#include<SFML/Graphics.hpp>
#include"../../Global/Support function.h"
#include"../Unit.h"

class Items: public sf::Drawable
{
protected:
	sf::Texture* textureItem;
	sf::String info;
	float x;
	float y;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
	virtual void use(Unit* unit) = 0;
	//„тобы текст был на новой строчке пишем \n
	sf::String show();
	void setPositionTexture(float x, float y);
	virtual ~Items() = default;
};
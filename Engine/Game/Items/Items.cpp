#include"Items.h"

void Items::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//TODO доделать метод draw
	sf::RectangleShape shape;
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(140, 140));
	shape.setTexture(textureItem);
	target.draw(shape);
}

sf::String Items::show()
{
	return info;
}

void Items::setPositionTexture(float x, float y)
{
	this->x = x;
	this->y = y;
}

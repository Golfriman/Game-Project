#include "Mouse.h"

Mouse::Mouse(sf::RenderWindow* window)
{
    mouse = new sf::Mouse;
    this->window = window;
}

sf::Vector2f Mouse::getCoordinate()
{
    return window->mapPixelToCoords(mouse->getPosition(*window));
}

sf::Mouse* Mouse::getMouse()
{
    return mouse;
}

Mouse::~Mouse()
{
    delete mouse;
    mouse = nullptr;
}

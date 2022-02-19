#include"Button.h"

Button::Button(int id,short& xPosition, short& yPosition, short& width, short& height, sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* activeTexture, sf::Texture* switchOnTexture, sf::Texture* switchOffTexture)
{
      
      stateColor = 0;
      this->id = id;
      rect = new sf::RectangleShape;
      rect->setPosition(xPosition, yPosition);
      rect->setSize(sf::Vector2f(width, height));
      mode = new ModeButton(idleTexture, hoverTexture, activeTexture, switchOnTexture, switchOffTexture);
      if (idleTexture)
      {

          rect->setTexture(idleTexture);
      }
  }

void Button::setIdle()
{
       stateColor = 0;
       rect->setTexture(mode->getIdle());
   }

void Button::setHover()
{
    stateColor = 1;
    rect->setTexture(mode->getHover());
}

void Button::setActive()
{
    stateColor = 2;
    rect->setTexture(mode->getActive());
}

void Button::setOn()
{
    stateColor = 3;
    rect->setTexture(mode->getSwitchOn());
}

void Button::setOff()
{
    rect->setTexture(mode->getSwitchOff());

}

sf::RectangleShape& Button::getRect()const
{
    return *rect;
}

int& Button::getStateColor()
{
    return stateColor;
}

int& Button::getState()
{
    return id;
}

void Button::setOnClick(std::function<void()>& onClick)
{
    this->onClick = &onClick;
}

void Button::startClick()
{
    std::function<void()> function = *onClick;
    function();
}

Button::~Button()
{
    if (rect)
    {
        delete rect;
        rect = nullptr;
    }
    delete mode;
    mode = nullptr;
}

bool Button::containsCursor(sf::Vector2f& const coordinate)
{
    return rect->getGlobalBounds().contains(coordinate);
}

ModeButton::ModeButton(sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* activeTexture, sf::Texture* switchOnTexture, sf::Texture* switchOffTexture)
{
    this->idleTexture = idleTexture;
    this->hoverTexture = hoverTexture;
    this->activeTexture = activeTexture;
    this->switchOffTexture = switchOffTexture;
    this->switchOnTexture = switchOnTexture;
}

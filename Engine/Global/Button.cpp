#include"Button.h"
bool Coordinate::operator==(const Coordinate& other) const
{
	return this->x == other.x && this->y == other.y;
}

bool Coordinate::operator!=(const Coordinate& other) const
{
	return this->x != other.x && this->y != other.y;
}

Button::Button(int id,short& xPosition, short& yPosition, short& width, short& height, sf::Text* text, sf::Color* idleColor, sf::Color* hoverColor, sf::Color* activeColor, sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* activeTexture)
{
      stateColor = 0;
      this->id = id;
      rect = new sf::RectangleShape;
      this->text = text;
      this->idleColor = idleColor;
      this->hoverColor = hoverColor;
      this->activeColor = activeColor;
      this->idleTexture = idleTexture;
      this->hoverTexture = hoverTexture;
      this->activeTexture = activeTexture;
      rect->setPosition(xPosition, yPosition);
      rect->setSize(sf::Vector2f(width, height));
      //rect->setOutlineColor(sf::Color::Black);
      //rect->setOutlineThickness(1);
      if (idleColor)
      {
          rect->setFillColor(*idleColor);
      }
      else if (idleTexture)
      {

          rect->setTexture(idleTexture);
      }
      else
      {
          std::cout << "Вы ебобо, что ты хочешь от мене, где данные мразь...";
      }
  }

void Button::setIdle()
{
       stateColor = 0;
       if (idleColor)
       {
           rect->setFillColor(*idleColor);
       }
       else {
           rect->setTexture(idleTexture);
       }
   }

void Button::setHover()
{
    stateColor = 1;
    if (hoverColor)
    {
        rect->setFillColor(*hoverColor);
    }
    else if (hoverTexture)
    {
        rect->setTexture(hoverTexture);
    }
}

void Button::setActive()
{
    stateColor = 2;
    if (activeColor)
    {
        rect->setFillColor(*activeColor);
    }
    else if (activeTexture)
    {
        rect->setTexture(activeTexture);
    }
}

sf::RectangleShape& Button::getRect()
{
    return *rect;
}

sf::Text* Button::getText()
{
    return text;
}

int& Button::getStateColor()
{
    return stateColor;
}

int& Button::getState()
{
    return id;
}

Button::~Button()
{
    if (rect)
    {
        delete rect;
        rect = nullptr;
    }
}
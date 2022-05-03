#include "Unit.h"

void Unit::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (isDead())
    {
        return;
    }
    target.draw(*spriteUnit);
    

}

uint8_t Unit::getNumberOfAction()
{
    return characterisitcs->getNumberOfAction();
}

void Unit::setBlock()
{
    block = true;
}

Unit::Unit()
{
    spriteUnit = new sf::RectangleShape;
}

void Unit::updateSprite()
{
}

void Unit::updateStateAnimation()
{
}

void Unit::showHealthBar(bool showHealth)
{
    show = showHealth;
}

void Unit::attackWithALightAttack(Unit* unit)
{
    uint16_t* number = &this->characterisitcs->getNumberOfAction();
    *number -= 1;
    if (unit->block)
    {
        /*Процент блока*/
        unit->getCharacteristics()->changeHealth(0);
        return;
    }
    unit->getCharacteristics()->changeHealth(-1 * this->getCharacteristics()->getDamage());
}

void Unit::attackWithAHeavyAttack(Unit* unit)
{

    uint16_t& number = unit->getCharacteristics()->getNumberOfAction();
    number -= 2;

    if (unit->block)
    {
        /*Процент блока*/
        unit->getCharacteristics()->changeHealth(0);
        return;
    }
    unit->getCharacteristics()->changeHealth(-1*this->getCharacteristics()->getDamage()*1.5f);
}

Characteristics* Unit::getCharacteristics()
{
    return characterisitcs;
}

bool Unit::isDead()const
{
    return characterisitcs->isDead();
}

Unit::~Unit()
{
    delete characterisitcs;
    characterisitcs = nullptr;

    delete spriteUnit;
    spriteUnit = nullptr;
}

#include "Unit.h"

float Unit::blockDamage()
{
    srand(time(nullptr));
    int r = rand() % 25;
    return r / 100.f;
}

void Unit::critDamage(auto& damage)
{
    int random = rand() % 1000;
    if (random <= this->characterisitcs->getLucky())
    {
        std::cout << "LOG: CRITICAL DAMAGE\n";
        damage *= 1.5;
    }

}

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
    block = false;
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
    int16_t& number = this->characterisitcs->getNumberOfAction();
    if (number < 1)
    {
        std::cout << "haha\n";
        return;
    }
    number -= 1;
    int random = rand() % 1000;
    if (random <= unit->characterisitcs->getDexterity())
    {
        std::cout << "LOG:Miss\n";
        return;
    }
    if (this->block)
    {
        int16_t getDamage = -1 * this->getCharacteristics()->getDamage() * blockDamage();
        critDamage(getDamage);
        unit->getCharacteristics()->changeHealth(getDamage);
        block = !block;
        return;
    }
    auto getDamage = -1 * this->getCharacteristics()->getDamage();
    critDamage(getDamage);
    unit->getCharacteristics()->changeHealth(getDamage);
}

void Unit::attackWithAHeavyAttack(Unit* unit)
{

    int16_t& number = this->characterisitcs->getNumberOfAction();
    if (number < 3)
    {
        std::cout << "haha\n";
        return;
    }
    number -= 3;
    int random = rand() % 1000;
    if (random <= unit->characterisitcs->getDexterity())
    {
        std::cout << "LOG:Miss\n";
        return;
    }
    if (this->block)
    {
        int16_t getDamage = -1 * this->getCharacteristics()->getDamage() * 1.5f * blockDamage();
        critDamage(getDamage);
        unit->getCharacteristics()->changeHealth(getDamage);
        block = !block;
        return;
    }
    int16_t getDamage = -1 * this->getCharacteristics()->getDamage() * 1.5f;
    critDamage(getDamage);
    unit->getCharacteristics()->changeHealth(getDamage);
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

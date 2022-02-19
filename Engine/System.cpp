#include "System.h"

System::System()
{
    titleFont = new sf::Font;
    normalFont = new sf::Font;
    state = 0;
    window.setWindow();
    mouse = new Mouse(window.getHandle());
    if (!titleFont->loadFromFile("resources//Fonts//ShadowsIntoLightTwo-Regular.TTF") || !normalFont->loadFromFile("resources//Fonts//Montserrat-Regular.TTF"))
    {
        window.getHandle()->close();
        window.getHandle()->create(sf::VideoMode(300, 50), "Error");
        /*Logic*/
    }
}

sf::RenderWindow* System::getHandle()
{
    return window.getHandle();
}

Window& System::getWindow()
{
    return window;
}

Audio& System::getAudio()
{
    return audio;
}

Keyboard& System::getKeyboard()
{
    return keyboard;
}

Mouse* System::getMouse()
{
    return mouse;
}

int& System::getState()
{
    return state;
}

sf::Font* System::getTitleFont()
{
    return titleFont;
}

sf::Font* System::getNormalFont()
{
    return normalFont;
}

System::~System()
{
    if (normalFont)
    {
        delete normalFont;
        normalFont = nullptr;
    }
    if (titleFont)
    {
        delete titleFont;
        titleFont = nullptr;
    }
    if (mouse)
    {
        delete mouse;
        mouse = nullptr;
    }
}

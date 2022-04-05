#include "System.h"

System::System()
{
    event = new sf::Event;
    titleFont = new sf::Font;
    normalFont = new sf::Font;
    window.setWindow();
    mouse = new Mouse(window.getHandle());
    if (!titleFont->loadFromFile("resources//Fonts//littletroublegirlbv.TTF") || !normalFont->loadFromFile("resources//Fonts//Montserrat-Regular.TTF"))
    {
        window.getHandle()->close();
        window.getHandle()->create(sf::VideoMode(300, 200), "Error");
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


sf::Font* System::getTitleFont()
{
    return titleFont;
}

sf::Font* System::getNormalFont()
{
    return normalFont;
}

sf::Event* System::getEvent()
{
    return event;
}

System::~System()
{
    deleteObject(normalFont);
    deleteObject(titleFont);
    deleteObject(mouse);
    deleteObject(event);
}

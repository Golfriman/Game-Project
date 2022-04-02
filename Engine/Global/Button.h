#pragma once
#include<SFML/Graphics.hpp>
#include<unordered_map>
#include<iostream>
#include<functional>

class ModeButton
{
    sf::Texture* idleTexture, * hoverTexture, * activeTexture, * switchOnTexture, * switchOffTexture;
public:
    ModeButton(sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr, sf::Texture* switchOnTexture = nullptr, sf::Texture* switchOffTexture = nullptr);
    sf::Texture* getIdle()
    {
        return idleTexture;
    }
    sf::Texture* getHover()
    {
        return hoverTexture;
    }
    sf::Texture* getActive()
    {
        return activeTexture;
    }
    sf::Texture* getSwitchOn()
    {
        return switchOnTexture;
    }
    sf::Texture* getSwitchOff()
    {
        return switchOffTexture;
    }

};

class Button
{
    sf::RectangleShape* rect;
    ModeButton* mode;
   
    int stateColor, id;
 
    std::function<void()>* onClick;
public:
    Button() = default;
    Button(const Button& copySource) = delete;
    Button& operator=(const Button& copySource) = delete;

    Button(int id,short& xPosition, short& yPosition, short& width, short& height, sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr, sf::Texture* switchOnTexture = nullptr, sf::Texture* switchOffTexture = nullptr);
    
    void setIdle();
   
    void setHover();
 
    void setActive();

    void setOn();
    
    void setOff();
    
    sf::RectangleShape& getRect() const;

    int& getStateColor();

    int& getState();

    void setOnClick(std::function<void()>& onClick);

    void startClick();

    bool containsCursor(const sf::Vector2f& coordinate);

    ~Button();
};
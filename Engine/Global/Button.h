#pragma once
#include<SFML/Graphics.hpp>
#include<unordered_map>
#include<iostream>
#include<functional>
struct Coordinate
{
    short x, y;
    bool operator==(const Coordinate& other)const;
    bool operator!=(const Coordinate& other)const;
};

namespace std
{
    template<>
    struct hash<Coordinate>
    {
        std::size_t operator()(const Coordinate& object)const
        {
            return std::hash<short>()(object.x) ^ std::hash<short>()(object.y) << 1;
        }
    };
}

class Button
{
    sf::RectangleShape* rect;
    sf::Text* text;
    sf::Color* idleColor, * hoverColor, * activeColor, *switchOnColor, *switchOffColor;
    sf::Texture* idleTexture, * hoverTexture, * activeTexture, *switchOnTexture, *switchOffTexture;
    int stateColor, id;
    std::function<void()> onClick;
public:
    Button() = default;
    Button(const Button& copySource) = delete;
    Button& operator=(const Button& copySource) = delete;

    Button(int id,short& xPosition, short& yPosition, short& width, short& height, sf::Text* text = nullptr, sf::Color* idleColor = nullptr, sf::Color* hoverColor = nullptr, sf::Color* activeColor = nullptr, sf::Color* switchOnColor = nullptr, sf::Color* switchOffColor = nullptr,sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr, sf::Texture* switchOnTexture = nullptr, sf::Texture* switchOffTexture = nullptr);
    
    void setIdle();
   
    void setHover();
 
    void setActive();

    void setOn();
    
    void setOff();
    
    sf::RectangleShape& getRect();

    sf::Text* getText();

    int& getStateColor();

    int& getState();

    void setOnClick(std::function<void()>* onClick);

    void startClick();

    ~Button();
};
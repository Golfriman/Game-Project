#pragma once
#include<SFML/Graphics.hpp>
#include<unordered_map>
#include<iostream>
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
    sf::Color* idleColor, * hoverColor, * activeColor;
    sf::Texture* idleTexture, * hoverTexture, * activeTexture;
    int stateColor, id;
public:
    Button() = default;

    Button(int id,short& xPosition, short& yPosition, short& width, short& height, sf::Text* text = nullptr, sf::Color* idleColor = nullptr, sf::Color* hoverColor = nullptr, sf::Color* activeColor = nullptr,sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr);
    
    void setIdle();
   
    void setHover();
 
    void setActive();
    
    sf::RectangleShape& getRect();

    sf::Text* getText();

    int& getStateColor();

    int& getState();

    ~Button();
};
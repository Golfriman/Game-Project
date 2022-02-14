#include "Support function.h"

void loadFont(const sf::String path, sf::Font& font)
{
    if (!font.loadFromFile(path))
    {
        
    }
}

void loadTexture(sf::String path, sf::Texture* texture)
{
    if (!texture->loadFromFile(path))
    {
        std::cerr << "Error";
    }
}

void setText(sf::String string, sf::Text& text, const sf::Font& font, int xPostion, int yPosition, sf::Color& color, int size)
{
    text.setString(string);
    text.setFont(font);
    text.setFillColor(color);
    text.setPosition(xPostion, yPosition);
    text.setCharacterSize(size);
}

void insertButton(int id,std::unordered_map<Coordinate, Button*>& buttons, std::vector<Coordinate>& vector, short xPosition, short yPosition, short width, short height, short size, sf::String string, sf::Font* font, sf::Color textColor, sf::Color* idleColor, sf::Color* hoverColor, sf::Color* activeColor, sf::Color* switchOnColor, sf::Color* switchOffColor, sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* activeTexture, sf::Texture *switchOnTexture, sf::Texture *switchOffTexture)
{
    sf::Text* text = nullptr;
    if (font)
    {
        text = new sf::Text;
        setText(string, *text, *font, xPosition, yPosition, textColor, size);

    }
    Button* button = new Button(id ,xPosition, yPosition, width, height, text, idleColor, hoverColor, activeColor, switchOnColor, switchOffColor, idleTexture, hoverTexture, activeTexture, switchOnTexture, switchOffTexture);
    Coordinate beginShape{ xPosition, yPosition };
    vector.push_back(beginShape);
    for (short int x1 = xPosition, x2 = xPosition + width; x1 < x2; x1++)
    {
        for (short int y1 = yPosition, y2 = yPosition + height; y1 < y2; y1++)
        {
            Coordinate point;
            point.x = x1;
            point.y = y1;
            buttons.insert(std::make_pair(point, button));
        }
    }
}

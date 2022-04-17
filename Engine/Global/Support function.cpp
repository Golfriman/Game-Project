#include "Support function.h"


void loadFont(const sf::String path, sf::Font& font)
{
    if (!font.loadFromFile(path))
    {
        exit(1);
    }
}

void loadTexture(sf::String path, sf::Texture* texture)
{
    if (!texture->loadFromFile(path))
    {
        exit(1);
    }
}

void setText(sf::String string, sf::Text& text, const sf::Font* font, int xPostion, int yPosition, sf::Color& color, int size)
{
    text.setString(string);
    text.setFont(*font);
    text.setFillColor(color);
    text.setPosition(xPostion, yPosition);
    text.setCharacterSize(size);
}

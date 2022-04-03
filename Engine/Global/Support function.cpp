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

void insertButton(int id, std::vector<Button*>& vector, short xPosition, short yPosition, short width, short height, sf::Texture* idleTexture, sf::Texture* hoverTexture, sf::Texture* activeTexture, sf::Texture *switchOnTexture, sf::Texture *switchOffTexture)
{
    Button* button = new Button(id ,xPosition, yPosition, width, height, idleTexture, hoverTexture, activeTexture, switchOnTexture, switchOffTexture);
    vector.push_back(button);
}

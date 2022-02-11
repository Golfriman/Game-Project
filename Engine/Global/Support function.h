#pragma once
#include"Button.h"

template<typename T>
inline void deleteObject(T* object)
{
	delete object;
	object = nullptr;
}
template<typename T>
inline void deleteArrayObject(T* array)
{
	delete[] array;
	array = nullptr;
}
void loadFont(const sf::String path, sf::Font &font);
void loadTexture(sf::String path, sf::Texture* texture);
void setText(sf::String string, sf::Text& text, const sf::Font& font, int xPostion, int yPosition, sf::Color& color, int size);
void insertButton(int id, std::unordered_map<Coordinate, Button*>& buttons, std::vector<Coordinate>& vector, short xPosition, short yPosition, short width, short height, short size, sf::String string = "", sf::Font* font = nullptr, sf::Color text = sf::Color::Black, sf::Color* idleColor = nullptr, sf::Color* hoverColor = nullptr, sf::Color* activeColor = nullptr, sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr);
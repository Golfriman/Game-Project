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
void setText(sf::String string, sf::Text& text, const sf::Font* font, int xPostion, int yPosition, sf::Color& color, int size);
void insertButton(int id,std::vector<Button*>& vector, short xPosition, short yPosition, short width, short height, sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr, sf::Texture* switchOnTexture = nullptr, sf::Texture* switchOffTexture = nullptr);
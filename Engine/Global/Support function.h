#pragma once
#include"Button.h"

static constexpr int ID_MENU = 0x10;
static constexpr int ID_GAME = 0x11;
static constexpr int ID_SETTINGS = 0x12;
static constexpr int ID_JOURNAL = 0x13;
static constexpr int ID_EXIT = 0x14;
static constexpr int ID_NEXT = 0x15;
<<<<<<< Updated upstream
static constexpr int ID_DEATH = 0x16;
=======

static constexpr int ID_TALK_B = 0x19;
static constexpr int ID_MOD_B = 0x16;
static constexpr int ID_EXIT_B = 0x17;
static constexpr int ID_MENU_B = 0x18;

static constexpr int ID_S_ALTAR = 0x100;
static constexpr int ID_B_ALTAR = 0x101;
>>>>>>> Stashed changes



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
template<typename Container>
void insertButton(int id, Container& vector, short xPosition, short yPosition, short width, short height, sf::Texture* idleTexture = nullptr, sf::Texture* hoverTexture = nullptr, sf::Texture* activeTexture = nullptr, sf::Texture* switchOnTexture = nullptr, sf::Texture* switchOffTexture = nullptr)
{
	Button* button = new Button(id, xPosition, yPosition, width, height, idleTexture, hoverTexture, activeTexture, switchOnTexture, switchOffTexture);
	vector.push_back(button);
}
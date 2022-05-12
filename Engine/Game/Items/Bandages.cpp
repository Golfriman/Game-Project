#include "Bandages.h"

Bandages::Bandages()
{
	textureItem = new sf::Texture;
	info = L"Ѕинты - это хорошее средство чтобы остановить кровотечение,\nтакже они немного позвол€ют восстановить здоровье";
	loadTexture("resources//Image//Textures//band.png", textureItem);
}

void Bandages::use(Unit* unit)
{
	std::cout << "use bandages";
}

Bandages::~Bandages()
{
	delete textureItem;
	textureItem = nullptr;
}


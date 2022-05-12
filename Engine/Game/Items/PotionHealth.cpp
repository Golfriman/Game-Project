#include "PotionHealth.h"

PotionHealth::PotionHealth()
{
	textureItem = new sf::Texture;
	info = L"��������������� ��������� ���������� ��������";
	loadTexture("resources//Image//Textures//health.png", textureItem);
}


void PotionHealth::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(5);
}

PotionHealth::~PotionHealth()
{
	delete textureItem;
	textureItem = nullptr;
}

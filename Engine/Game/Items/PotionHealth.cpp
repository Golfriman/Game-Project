#include "PotionHealth.h"

PotionHealth::PotionHealth()
{
	textureItem = new sf::Texture;
	info = L"��������������� ��������� ���������� ��������";
	loadTexture("resources//Image//Textures//health.png", textureItem);
}


void PotionHealth::use(Unit* unit)
{
	unit->getCharacteristics()->changeHealth(unit->getCharacteristics()->getMaxHealth()*0.1f);
}

PotionHealth::~PotionHealth()
{
	delete textureItem;
	textureItem = nullptr;
}

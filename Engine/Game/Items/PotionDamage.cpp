#include "PotionDamage.h"

PotionDamage::PotionDamage()
{
	textureItem = new sf::Texture;
	info = L"����������� ���������� ���������� ����� ��\n��������� ���������� �������";
	loadTexture("resources//Image//Textures//powerDrink.png", textureItem);
}

void PotionDamage::use(Unit* unit)
{
	unit->getCharacteristics()->buff();
}

PotionDamage::~PotionDamage()
{
	delete textureItem;
	textureItem = nullptr;
}


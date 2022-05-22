#include "PotionDamage.h"

PotionDamage::PotionDamage()
{
	textureItem = new sf::Texture;
	info = L"Увеличивает количество наносящего урона на\nнекоторый промежуток времени";
	loadTexture("resources//Image//Textures//power.png", textureItem);
}

void PotionDamage::use(Unit* unit)
{
	unit->getCharacteristics()->changeCharacterisitics(5, 0, 0, 0, 0, 0);
}

PotionDamage::~PotionDamage()
{
	delete textureItem;
	textureItem = nullptr;
}


#include "PotionDamage.h"

PotionDamage::PotionDamage()
{
	//TODO �������� �����������
}

void PotionDamage::use(Unit* unit)
{
	unit->getCharacteristics()->buff();
}

sf::String PotionDamage::show()
{
	return sf::String{};
	//������� �� ����� ���������� � ������ �����
}

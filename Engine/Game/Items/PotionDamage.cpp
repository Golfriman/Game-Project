#include "PotionDamage.h"

PotionDamage::PotionDamage()
{
	//TODO �������� �����������
}

void PotionDamage::use(Unit* unit)
{
	unit->getCharacteristics()->buff();
}

void PotionDamage::show()
{
	//������� �� ����� ���������� � ������ �����
}

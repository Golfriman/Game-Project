#include"Dialog.h"

Dialog::Dialog(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);
	//��� ��� ������� � ����������� �� �������� ������
	dialog = {
	L"����� ���������� � ��� �������! �� �� ���� � ��� ����������!",
	L"� - ������ ������, ������� ������ � ������� ��������, ������� ��������\n����.",
	L"�, ��� �� ��� �� �����! ��, ��� ����, � ����� ����. ���������� ��������,\n ���� �� �������� ������ ���.",
	L"��� �� ���! ������� ��� ��� ������? ���� � �����? ����, �� �� ����� ����\n �����, � ��� ���� ��� �������.",
	L"��, � ����� �������, ��� �� �� ����������, ���� �� ������� �� �����, � ����\n ������ �����, ������ �� ������� ����������",
	L"��, ����� ����� �������, ������� �� ������, ��� � ����� ����������. �, � ���\n ����� �� �������� ����� ��� ����� ���������",
	L"�� ������ ��, �� ����� ����� ����� ����� ������� ���� ���, �������� ��������\n�� ��������� ������. � ����� � �������� ��� ���� ����� �� ����, � ��� ����\n� ������������� ������ � ��������� ���������. ��� ��� �����, ��������� ���\n�������,  � ���� ��������� ���."
	};

	next = [&]()
	{
		//������ �� ��� ������������ � ������ ��������.
		/*
		* ������ ��� ������.
		* 
		* �����:
		* 1. ��� �
		* 2. ��� �
		* ...
		* � ����� �� � ������� ������� �������, ���������, � ����� ������ ������ ����� � ��� ������� � ������ ��������. 
		* ������� �� ���� �����
		*/
		isBtnClick = false;
	};
	hello = [&]()
	{
		//� ������� Hello �������� � ������ 0
	};
	whereIam = [&]()
	{
		//��� � 3
	};
	wantExit = [&]()
	{

	};
	scaredDream = [&]()
	{

	};
	negation = [&]()
	{

	};
	why = [&]
	{

	};
}

void Dialog::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		/*����������� �������� ����*/
	}
}

void Dialog::render()
{
}

void Dialog::draw()
{
}

void Dialog::hud()
{
	handle->draw(sh_area);
	if (isBtnClick)
	{
		handle->draw(select[0]->getRect());
		handle->draw(ans);
		handle->draw(select_Text[0]);
	}
	else {
		for (int i = 0; i < select_Text.size(); i++)
		{
			handle->draw(select[i]->getRect());
			handle->draw(select_Text[i]);
		}
	}
}

void Dialog::createSource()
{

	area = new sf::Texture;
	st_button = new sf::Texture[2];
	select_Text.resize(2);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &st_button[0]);
	loadTexture("resources//Image//Textures//HoverButton0.png", &st_button[1]);
	loadTexture("resources//Image//Textures//dialog.png", area);
	sh_area.setPosition(420, 653);
	sh_area.setSize(sf::Vector2f(1046, 436));
	sh_area.setTexture(area);
	//495 720 ->930 295
	setText(dialog[1], ans, normallFont, 478, 720, white, 24);
	/*������ ����������*/
	setText(L"����������", select_Text[0], normallFont, 478, 720, white, 24);
	insertButton(0, select, 478, 720, 100, 100, &st_button[0], &st_button[1]);

	isBtnClick = true;

}

void Dialog::removeSource()
{
}

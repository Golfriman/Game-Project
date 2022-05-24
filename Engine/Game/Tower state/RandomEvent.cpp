#include "RandomEvent.h"


void RandomEvent::EventChest()
{
	text.resize(3);
	max = 1;
	t_btn.resize(3);
	setText(L" � ������� ����� � ���� �� ������. ������� ���� ������ ������,\n\
�� ���� ������� ��������, � ��� ������ �������.\n\
� �������� ������� ����� ������� �������� ������.\n\
� ������� � ������ ���������� A.B.B.A..\n\
������� ��� ���  ��������� ���� ���������� �����...", text[0], normallFont, 553, 799, white, n);
	setText(L"��� � ���������, ����� ������������� ����� ����.\n", text[1], normallFont, 553, 799, white, n);
	setText(L"����������\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"�������\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"�������\n", t_btn[2], normallFont, 1024, 959, white, n);

	act1 = [&]() {hero->setCoins(hero->getCoins()+100); };
	act2 = [&]() {act1(); };
	action_btn[0]->setOnClick(act1);
	action_btn[1]->setOnClick(act2);
	setText(L"�� �������� 100 �����!", text[2], normallFont, 553, 799, white, n);
}
void RandomEvent::EventMimik()
{
	text.resize(3);
	t_btn.resize(3);
	max = 1;
	setText(L"������� � ������� � �����, ���� ���������, ��� � ��������\n\
� ������, ������ ������. ����� ������ � ���������.\n\
� ������ ������� ��� ���������, �� ������� ����������\n\
�������� ������. �� ��� ���� � ����������� ������ �\n\
���������� ��������.�� ����� ����� � ���� � ����� �����...", text[0], normallFont, 553, 799, white, n);
	setText(L"��� �������. � �������� ���� � ������ � ����������\n\
�������� ���� ����� ��� ����.� ����� ...", text[1], normallFont, 553, 799, white, n);


	setText(L"����������", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"��������� ����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"������� ������\n", t_btn[2], normallFont, 1024, 959, white, n);
	setText(L"", text[2], normallFont, 553, 799, white, n);
	act1 = [&]() {text[2].setString(L"��� �������� �����, � � � ������ ������ �� ����..."); };
	act2 = [&]() {text[2].setString(L"��� �������� �����, �� ������ ���� �� ����.\n��� ������� 10 �����..."); hero->getCharacteristics()->changeHealth(-10); };
	action_btn[0]->setOnClick(act1);
	action_btn[1]->setOnClick(act2);


}
void RandomEvent::EventSacredAltar()
{
	max = 1;
	text.resize(3);
	t_btn.resize(3);
	setText(L"� ����� � ������� ������ ��������, �������� � �������.\n\
��������� ������ ����, � ������ �������� �����������\n\
�����. �� �������� ������� ������� ����. � ������� � �������� \n\
������. � ������� ���������� ���������� �������� �������, ��\n\
���� ������� ������ �����...\n", text[0], normallFont, 553, 799, white, n);
	setText(L"��� ������� � �� �����, � ������� ����� �����, ���������� ���-��.\n\
��������� ������� �� ��������� �������, � ���� ������\n\
������������. � ������� � ����� �...\n", text[1], normallFont, 553, 799, white, n);
	setText(L"", text[2], normallFont, 553, 799, white, n);

	setText(L"����������\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"�����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"������ � �����\n", t_btn[2], normallFont, 1024, 959, white, n);

	act1 = [&]() {text[2].setString(L"����� ���������, � � ��� �� ������ ����������."); };
	act2 = [&]() {text[2].setString(L"");
	std::mt19937 mersene;
	mersene.seed(time(nullptr));
	std::uniform_int_distribution<> n(0, 3);
	switch (n(mersene))
	{
	case 0:
		hero->getCharacteristics()->changeHealth(10);
		text[2].setString(L"�� ������� ������������ ��������");
		break;
	case 1:
		hero->getCharacteristics()->changeCharacterisitics(10, 0, 0, 0, 0, 0);
		text[2].setString(L"�� ��������� ��������� ����");
		break;
	case 2:
		hero->getCharacteristics()->changeCharacterisitics(0, 0, 0, 0, 10, 0);
		text[2].setString(L"�� ����� ����� ������");
		break;
	case 3:
		hero->getCharacteristics()->changeCharacterisitics(0, 0, 0, 10, 0, 0);
		text[2].setString(L"�� �������� ���� ������������ �����");
		break;
	default:
		break;
	}
 };

	action_btn[1]->setOnClick(act1);
	action_btn[0]->setOnClick(act2);

}
void RandomEvent::EventBloodyAltar()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
	setText(L"���� ������\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"�����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"�����\n", t_btn[2], normallFont, 946, 959, white, n);

	//����
}
void RandomEvent::EventTrap()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
			  
	setText(L"�������� �� ��������� ���� ���������! � ��� ��� ������ ������?\n\
�������� ������� �� ���������� � ���������, ��� �\n\
�� ������� �� ���� �������. �� � ���� ��� ����������\n\
����� �� ������, ���� ����������� ��������� �� ������\n\
�� ��������� ����...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"����� �� ����������\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"����� �� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventStone()
{
	text.resize(2);
	max = 1;
	t_btn.resize(3);
	setText(L" � ��� �� ���������������� ��������, ����� ���� ����\n\
������, ����� � ������. ������� ��� �������� �������.\n\
�� � ���� �������� ����� ���� � �� ��� �������� � \n\
������� ����. ���������� �������� ����� �������� ��\n\
����� ���� ���� � �� �� ����, ����� ��������� � �����...", text[0], normallFont, 553, 799, white, n);
	setText(L"�� ����.� ... ����� ��������� � ���������� �����������\n\
�� ���� � ��������� � ������� ��������, ������� ��� �����\n\
����, ��������  �������� ����.\n ", text[1], normallFont, 553, 799, white, n);
	setText(L"����������", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"������ ��� �����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"������ ��� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventBoiler()
{
	text.resize(1);
	max = 0;
	t_btn.resize(3);

	setText(L" ������ ����� ������� �����? ����� �������� �����\n\
������� ���������� �����. � ��� ���� ������ �������\n\
��������, �� ������� ������� ���������� �����.�����\n\
����� ��������. � ����� ...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"�����������\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"����� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTitle()
{
	text.resize(2);
	max = 1;
	t_btn.resize(2); 
	setText(L"	� ���������� � ������ �� ������ ��� �������� �������:\n\
There's not a soul out there No one to hear my prayer\n\
������� ��� �� ������ � ������. \n\
������ ����� ������� ����� ? ����� �������� �����\n\
Gimme gimme gimme a man after midnight  Won't...", text[0], normallFont, 553, 799, white, n);
	setText(L"somebody help me chase the shadows away.\n\
������� ������� ����� ����� �����, ��� ����� ������?\n", text[1], normallFont, 553, 799, white, n);
	setText(L"����������\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"���� ������\n", t_btn[1], normallFont, 646, 959, white, n);
}

void RandomEvent::EventViewTower()
{
	text.resize(3);
	max = 1;
	setText(L"������ � ������ ������ �������� �� ������?\n\
� ���� ������ ���������� �������, � ����� ��������� �\n\
�������� � ������� ������ �������. � ������� �������\n\
������� ���� �����-�� ����... �� �� ��� ����� ����\n\
������, ������������, ����� ���� � ����...", text[0], normallFont, 553, 799, white, n);
	setText("� �������� �� ���������� ������ � �����\n\
�������� ��������.���, ������� ��� ��������,\n\
��� ��������������. �� ���� ��������� ����,\n\
�������� ��������� �����, ������� � ������\n\
���.������ ������ �� ����.��� ��� ����������...", text[1], normallFont, 553, 799, white, n);
	setText(L"��� ����� ���� ������������ ��������� �� �����\n\
�������� ����������? ��� �������� �������,\n\
�� ����� ��� ������� ������������ ������ ����\n\
������. ���� �������, ��� �������.\n ", text[2], normallFont, 553, 799, white, n);
	
}

RandomEvent::RandomEvent(System& system, Hero* hero, bool*isLoadSource)
{
	init(system, hero, isLoadSource);
	white = sf::Color::White;
	countHistory = 0;
	next = [&]()
	{
		countHistory++;
		if (countHistory < text.size())
		{
			if (max == countHistory)
			{
				btn_enabled = true;
			}
			else
			{
				btn_enabled = false;
			}
		}
		else
		{
			std::cout << "NEXT";
			throw ID_NEXT;
		}
	};
}

void RandomEvent::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		sf::Vector2f coordinate = mouse->getCoordinate();
		if (btn_enabled)
		{
			for (auto& ui : action_btn)
			{
				ui->setIdle();
				if (ui->containsCursor(coordinate))
				{
					ui->setHover();
				}
			}
		}
		else
		{
			next_btn[0]->setIdle();
			if (next_btn[0]->containsCursor(coordinate))
			{
				next_btn[0]->setHover();
			}
		}
	}
	if (event->type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f coordinate = mouse->getCoordinate();
		if (btn_enabled)
		{
			for (auto& ui : action_btn)
			{
				if (ui->containsCursor(coordinate))
				{
					ui->startClick();
					next();
				}
			}
		}
		else
		{
			if (next_btn[0]->containsCursor(coordinate))
			{
				next();
			}
		}

	}
}

void RandomEvent::render()
{
}

void RandomEvent::draw()
{
}

void RandomEvent::hud()
{
	handle->draw(shape);
	if (btn_enabled)
	{
		for (auto& ui : action_btn)
		{
			handle->draw(ui->getRect());
		}
	}
	else
	{
		handle->draw(next_btn[0]->getRect());
	}
	handle->draw(text[countHistory]);
	if (btn_enabled)
	{
		for (int i = 1; i < t_btn.size(); i++)
		{
			handle->draw(t_btn[i]);
		}
	}
	else
	{
		handle->draw(t_btn[0]);
	}

	handle->draw(history);
}

void RandomEvent::createSource()
{
	isDelete = false;
	*isLoadSource = true;
	std::mt19937 mersenne{ reinterpret_cast<unsigned>(this) };

	std::uniform_int_distribution<int> num(0, 2);
	texture = new sf::Texture[3];
	loadTexture("resources//Image//Textures//RandomFrame.png", &texture[0]);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &texture[1]);
	loadTexture("resources//Image//Textures//HoverButton0.png", &texture[2]);
	insertButton(0, next_btn, 556, 949, 323, 49, &texture[1], &texture[2]);
	insertButton(0, action_btn, 556, 949, 323, 49, &texture[1], &texture[2]);
	insertButton(1, action_btn, 992, 949, 323, 49, &texture[1], &texture[2]);
	shape.setTexture(&texture[0], true);
	shape.setSize(sf::Vector2f(texture[0].getSize().x, texture[0].getSize().y));
	shape.setPosition(486.f, 719.f);
	switch (num(mersenne))
	{
	case 0:
	{
		EventChest();
	}break;
	case 1:
	{
		EventMimik();
	}break;
	case 2:
	{
		EventSacredAltar();
	}break;
	case 3:
	{
		EventTrap();
	}break;
	case 4:
	{
		EventStone();
	}break;
	case 5:
	{
		EventBoiler();
	}break;
	case 6:
	{
		EventTitle();
	}break;
	case 7:
	{
		EventViewTower();
	}break;
	}
	if (max == countHistory)
	{
		btn_enabled = true;
	}
}

void RandomEvent::removeSource()
{
	isDelete = true;
	deleteArrayObject(texture);
	for (auto& ui : action_btn)
	{
		deleteObject(ui);
	}
	for (auto& ui : next_btn)
	{
		deleteObject(ui);
	}
}

RandomEvent::~RandomEvent()
{
	if (isDelete) return;
	this->removeSource();
}

#include "RandomEvent.h"


void RandomEvent::EventEffectSurprise()
{
	text.resize(2);
	setText(L"������\n", text[0], normallFont, 553, 799, white, n);
	setText(L"����������\n", text[1], normallFont, 646, 959, white, n);
}
void RandomEvent::EventChest()
{
	text.resize(2);
	setText(L" � ������� ����� � ���� �� ������. ������� ���� ������ ������,\n\
�� ���� ������� ��������, � ��� ������ �������.\n\
� �������� ������� ����� ������� �������� ������.\n\
� ������� � ������ ���������� A.B.B.A..\n\
������� ��� ���  ��������� ���� ���������� �����. \n\
��� � ���������, ����� ������������� ����� ����.\n", text[0], normallFont, 553, 799, white, n);
	setText(L"�������\n", text[1], normallFont, 646, 959, white, n);

}
void RandomEvent::EventMimik()
{
	text.resize(3);
	t_btn.resize(3);
	setText(L"������� � ������� � �����, ���� ���������, ��� � �������� � ������, ������ ������.\n\
����� ������ � ���������. � ������ ������� ��� ���������,  �� ������� ���������� �������� ������.\n\
�� ��� ���� � ����������� ������ � ���������� ��������. �� ����� ����� � ���� � ����� �����\n\
��� �������.\n� �������� ���� � ������ � ���������� �������� ���� ����� ��� ����. � ����� ...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"��������� ����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"������� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventSacredAltar()
{
	max = 1;
	text.resize(2);
	t_btn.resize(3);
	setText(L"\t� ����� � ������� ������ ��������, �������� � �������.\n\
��������� ������ ����, � ������ �������� �����������\n\
�����. �� �������� ������� ������� ����. � ������� � �������� \n\
������. � ������� ���������� ���������� �������� �������, ��\n\
���� ������� ������ �����...\n", text[0], normallFont, 553, 799, white, n);
	setText(L"��� ������� � �� �����, � ������� ����� �����, ���������� ���-��.\n\
��������� ������� �� ��������� �������, � ���� ������\n\
������������. � ������� � ����� �...\n", text[1], normallFont, 553, 799, white, n);
	setText(L"����������\n", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"�����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"������ � �����\n", t_btn[2], normallFont, 1024, 959, white, n);

}
void RandomEvent::EventBloodyAltar()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
	setText(L"���� ������\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"�����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"�����\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTrap()
{
	text.resize(3);
	t_btn.resize(3);
	setText(L"�������� �� ��������� ���� ���������! � ��� ��� ������ ������?\n\
�������� ������� �� ���������� � ���������, ��� � �� ������� �� ���� �������.\n\
�� � ���� ��� ���������� ����� �� ������, ���� ����������� ��������� �� ������\n\
�� ��������� ����...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"����� �� ����������\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"����� �� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventStone()
{
	text.resize(3);
	t_btn.resize(3);
	setText(L" � ��� �� ���������������� ��������, ����� ���� ���� ������, ����� � ������.\n\
������� ��� �������� �������. �� � ���� �������� ����� ���� � �� ��� �������� � ������� ����.\n\
���������� �������� ����� �������� �� ����� ���� ���� � �� �� ����, ����� ��������� � ����� �� ����.\n\
� ... ����� ��������� � ���������� ����������� �� ���� � ���������\n\
� ������� ��������, ������� ��� ����� ����, ��������  �������� ����.\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"����������", t_btn[0], normallFont, 646, 959, white, n);
	setText(L"������ ��� �����\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"������ ��� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventBoiler()
{
	text.resize(3);
	max = 0;
	t_btn.resize(3);
	setText(L" ������ ����� ������� �����? ����� �������� ����� ������� ���������� �����\n\
� ��� ���� ������ ������� ��������, �� ������� ������� ���������� �����.\n\
����� ����� ��������.\n � ����� ...\n ", text[0], normallFont, 553, 799, white, n);
	setText(L"�����������\n", t_btn[1], normallFont, 646, 959, white, n);
	setText(L"����� ������\n", t_btn[2], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTitle()
{
	text.resize(2);
	max = -1;
	t_btn.resize(1);
	setText(L"	� ���������� � ������ �� ������ ��� �������� �������:\n\
There's not a soul out there No one to hear my prayer\n\
������� ��� �� ������ � ������. \n\
Gimme gimme gimme a man after midnight  Won't somebody help me chase the shadows away .\n\
������� ������� ����� ����� �����, ��� ����� ������?\n", text[0], normallFont, 553, 799, white, n);
	setText(L"���� ������\n", t_btn[1], normallFont, 646, 959, white, n);
}
void RandomEvent::EventDeadFriend()
{
	text.resize(1);
	setText(L" ������� �����������\n ", text[0], normallFont, 553, 799, white, n);
	//setText(L"�����")
}
void RandomEvent::EventNoiseFighting()
{
	text.resize(1);
	setText(L"��� ������\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventOffice()
{
	text.resize(1);
	setText(L"������� ����\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventStrawDoll()
{
	text.resize(1);
	setText(L"���������� �����\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventViewTower()
{
	text.resize(1);
	setText(L"������ � ������ ������ �������� �� ������?\n\
� ���� ������ ���������� �������, � ����� ��������� �\n\
�������� � ������� ������ �������. � ������� �������\n\
������� ���� �����-�� ����... �� �� ��� ����� ����\n\
������, ������������, ����� ���� � ����.\n\
� �������� �� ���������� ������ � �����\n\
�������� ��������.���, ������� ��� ��������,\n\
��� ��������������.\n�� ���� ��������� ����,\n\
�������� ��������� �����, ������� � ������\n\
���.������ ������ �� ����.��� ��� ����������,\n\
��� ����� ���� ������������ ��������� �� �����\n\
�������� ����������? \n��� �������� �������,\n\
�� ����� ��� ������� ������������ ������ ����\n\
������. ���� �������, ��� �������.\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventHallucinations()
{
	text.resize(1);
	setText(L"�����������\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventCorpse()
{
	text.resize(1);
	setText(L"���-�� ����...\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventReflections()
{
	text.resize(1);
	setText(L"�����������\n ", text[0], normallFont, 553, 799, white, n);
	
}

RandomEvent::RandomEvent(System& system, Hero* hero, bool*isLoadSource)
{
	init(system, hero, isLoadSource);
	white = sf::Color::White;
	countHistory = 0;
	next = [&]()
	{
		if (countHistory < text.size())
		{
			countHistory++;
			if (max == countHistory)
			{
				btn_enabled = true;
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

	std::uniform_int_distribution<int> num(0, 3);
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
	int test = 3;
	switch (test)
	{
	case 0:
	{
		EventEffectSurprise();
		break;
	}
	case 1:
	{
		EventChest();
	}break;
	case 2:
	{
		EventMimik();
	}break;
	case 3:
	{
		EventSacredAltar();
	}break;
	case 4:
	{
		EventBloodyAltar();
	}break;
	case 5:
	{
		EventTrap();
	}break;
	case 6:
	{
		EventStone();
	}break;
	case 7:
	{
		EventBoiler();
	}break;
	case 8:
	{
		EventTitle();
	}break;
	case 9:
	{
		EventDeadFriend();
	}break;
	case 10:
	{
		EventNoiseFighting();
	}break;
	case 11:
	{
		EventOffice();
	}break;
	case 12:
	{
		EventStrawDoll();
	}break;
	case 13:
	{
		EventViewTower();
	}break;
	case 14:
	{
		EventHallucinations();
	}break;
	case 15:
	{
		EventCorpse();
	}break;
	case 16:
	{
		EventReflections();
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

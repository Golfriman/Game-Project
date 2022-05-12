#include "RandomEvent.h"


void RandomEvent::EventEffectSurprise()
{
	
	
	////�������� 
	//texture = new sf::Texture[4];
	////�������� ��������
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	////������ ������� ������
	text.resize(1);
	//���������� �����
	setText(L"������\n", text[0], normallFont, 553, 799, white, n);

	text.resize(1);
	setText(L"����������\n", text[0], normallFont, 646, 959, white, n);
}
void RandomEvent::EventChest()
{
	texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//RandomFrame.png", &texture[0]);
	/*texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//...", &texture[0]);*/
	text.resize(1);
	setText(L" � ������� ����� � ���� �� ������. ������� ���� ������ ������, �� ���� ������� ��������, � ��� ������ �������. \n � �������� ������� ����� ������� �������� ������.\n � ������� � ������ ���������� A.B.B.A..\n ������� ��� ���  ��������� ���� ���������� �����. ��� � ���������, ����� ������������� ����� ����.\n", text[0], normallFont, 553, 799, white, n);
	//insertButton(1, buttons, 0, 0, 0, 0, &texture[0]);
	text.resize(1);
	setText(L"�������\n", text[0], normallFont, 646, 959, white, n);

}
void RandomEvent::EventMimik()
{
	/*texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//...", &texture[0]);*/
	text.resize(1);
	setText(L"������� � ������� � �����, ���� ���������, ��� � �������� � ������, ������ ������. \n����� ������ � ���������. � ������ ������� ��� ���������,  �� ������� ���������� �������� ������. \n �� ��� ���� � ����������� ������ � ���������� ��������. �� ����� ����� � ���� � ����� ����� ��� �������.\n� �������� ���� � ������ � ���������� �������� ���� ����� ��� ���� . � ����� ...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"��������� ����\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"������� ������\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventSacredAltar()
{
	/*texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//...", &texture[0]);*/
	text.resize(1);
	setText(L"� ����� � ������� ������ ��������, �������� � �������. ��������� ������ ����, � ������ �������� ����������� �����.\n �� �������� ������� ������� ����. � ������� � �������� ������.  � ������� ���������� ���������� �������� �������,\n  �� ���� ������� ������ �����. ��� ������� � �� �����, � ������� ����� �����, ���������� ���-��.\n ��������� ������� �� ��������� �������, � ���� ������ ������������.\n � ������� � ����� �...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"�����\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"�����\n", text[0], normallFont, 946, 959, white, n);

}
void RandomEvent::EventBloodyAltar()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"���� ������\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"�����\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"�����\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTrap()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"�������� �� ��������� ���� ���������! � ��� ��� ������ ������? \n �������� ������� �� ���������� � ���������, ��� � �� ������� �� ���� �������. �� � ���� ��� ���������� ����� �� ������, ���� ����������� ��������� �� ������ �� ��������� ����...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"����� �� ����������\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"����� �� ������\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventStone()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L" � ��� �� ���������������� ��������, ����� ���� ���� ������, ����� � ������. ������� ��� �������� �������. �� � ���� �������� ����� ���� � �� ��� �������� � ������� ����.\n ���������� �������� ����� �������� �� ����� ���� ���� � �� �� ����, ����� ��������� � ����� �� ����. \n � ... ����� ��������� � ���������� ����������� �� ���� � ��������� � ������� ��������, ������� ��� ����� ����, ��������  �������� ����.\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"������ ��� �����\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"������ ��� ������\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventBoiler()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L" ������ ����� ������� �����? ����� �������� ����� ������� ���������� �����.\n � ��� ���� ������ ������� ��������, �� ������� ������� ���������� �����. ����� ����� ��������.\n � ����� ...\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"�����������\n", text[0], normallFont, 646, 959, white, n);
	text.resize(1);
	setText(L"����� ������\n", text[0], normallFont, 946, 959, white, n);
}
void RandomEvent::EventTitle()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"  � ���������� � ������ �� ������ ��� �������� �������:\nThere's not a soul out there No one to hear my prayer \n������� ��� �� ������ � ������. \nGimme gimme gimme a man after midnight  Won't somebody help me chase the shadows away .\n ������� ������� ����� ����� �����, ��� ����� ������?\n ", text[0], normallFont, 553, 799, white, n);
	text.resize(1);
	setText(L"����������\n", text[0], normallFont, 646, 959, white, n);
}
void RandomEvent::EventDeadFriend()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L" ������� �����������\n ", text[0], normallFont, 553, 799, white, n);
}
void RandomEvent::EventNoiseFighting()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"��� ������\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventOffice()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"������� ����\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventStrawDoll()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"���������� �����\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventViewTower()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"������ � ������ ������ �������� �� ������? � ���� ������ ���������� �������, � ����� ��������� � �������� � ������� ������ �������. � ������� ������� ������� ���� �����-�� ����...\n �� �� ��� ����� ���� ������, ������������, ����� ���� � ����. � �������� �� ���������� ������ � ����� �������� ��������.���, ������� ��� ��������, ��� ��������������.\n�� ���� ��������� ����, �������� ��������� �����, ������� � ������ ���.������ ������ �� ����.��� ��� ����������, ��� ����� ���� ������������ ��������� �� ����� �������� ����������? \n��� �������� �������, �� ����� ��� ������� ������������ ������ ���� ������. ���� �������, ��� �������.\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventHallucinations()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"�����������\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventCorpse()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"���-�� ����...\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent::EventReflections()
{
	//texture = new sf::Texture[4];
	//loadTexture("resources//Image//Textures//...", &texture[0]);
	text.resize(1);
	setText(L"�����������\n ", text[0], normallFont, 553, 799, white, n);
	
}
void RandomEvent ::CreateRect()
{
	area.setPosition(486, 719);
	area.setSize(sf::Vector2f(944, 334));
	area.setTexture(&texture[0], true);
}

RandomEvent::RandomEvent(System& system, Hero* hero, bool*isLoadSource)
{
	init(system, hero, isLoadSource);
	white = sf::Color::White;
}

void RandomEvent::update()
{
	
}

void RandomEvent::render()
{
}

void RandomEvent::draw()
{
}

void RandomEvent::hud()
{
	handle->draw(area);
	for (auto& ui : buttons)
	{
		handle->draw(ui->getRect());
	}
	for (auto& uiText : text)
	{
		handle->draw(uiText);
	}
	
}

void RandomEvent::createSource()
{
	*isLoadSource = true;
	std::mt19937 mersenne{ reinterpret_cast<unsigned>(this) };
	std::uniform_int_distribution<int> num(0, 3);
	texture = new sf::Texture[4];
	loadTexture("resources//Image//Textures//RandomFrame.png", &texture[0]);
	loadTexture("resources//Image//Textures//RandomEventButton.png", &texture[1]);
	insertButton(0, buttons, 556, 949, 323, 49, &texture[1]);
	
	CreateRect();
	
	switch (num(mersenne))
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
}

void RandomEvent::removeSource()
{
}

RandomEvent::~RandomEvent()
{
}

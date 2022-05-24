#pragma once
#include"BlacksmithEvent.h"
/*
* ������ � ��� ��������� ������. � � ����� ������ �� ������������� ����, ������ ��� ��� �������� ��� ����� ����� �����.
* �� ��� ��� ��� �� ��� ������, �������� ����. ��� ����� �� ������ ������, � ������ ����������� ������, �������� �������, 
* � ����� �� ��� ���� ���������� ��� ����������
*/
class Dialog : public BlacksmithEvent
{
	std::vector<sf::String> dialog;
	std::vector<sf::Text> select_Text;
	std::vector<Button*> select;
	sf::Text ans;
	bool isBtnClick = false;
	sf::Texture* area;
	sf::RectangleShape sh_area;
	sf::Color white = sf::Color::White;
	sf::Texture* st_button;
	//������������� ������, ��� ����� ����� ��� ����� ����������
	int stateText;
	std::function<void()> enoughTalk;
	std::function<void()> hello;
	std::function<void()> whereIam;
	std::function<void()> wantExit;
	std::function<void()> scaredDream;
	std::function<void()> negation;
	std::function<void()> why;
public:
	Dialog(System& system, Hero* hero, bool* isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
};

#pragma once
#include"BlacksmithEvent.h"
/*
*  ороче € тут попыталс€ помочь. » € хотел отойти от предложенного вида, потому что мне казалось что снизу будет лучше.
* Ќу так как это не мо€ задача, оставл€ю тебе. “ут вроде бы только кнопки, и логику отображени€ текста, осталось сделать, 
* € вроде бы как смог постаралс€ все расставить
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
	//»нициализаци€ текста, тип какой текст нам нужно отображать
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

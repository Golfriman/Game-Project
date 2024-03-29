#pragma once
#include"TowerState.h"

class RandomEvent : public TowerState
{
	sf::Color white;
	static constexpr int n = 24;
	std::vector<Button*> action_btn;
	std::vector<Button*> next_btn;
	sf::Texture* texture;
	std::vector<sf::Text> text;
	std::vector<sf::Text> t_btn;
	size_t max;
	sf::RectangleShape area;
	bool btn_enabled = false;
	void EventChest();
	void EventMimik();
	void EventSacredAltar();
	void EventBloodyAltar();
	void EventTrap();
	void EventStone();
	void EventBoiler();
	void EventTitle();
	void EventViewTower();
	sf::RectangleShape shape;
	sf::Text history;
	std::vector<sf::String> textHistory;
	std::function<void()> next;
	std::function<void()> act1;
	std::function<void()> act2;
	size_t countHistory;
	bool isDelete = false;
public:
	RandomEvent(System& system, Hero* hero, bool *isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~RandomEvent();
};
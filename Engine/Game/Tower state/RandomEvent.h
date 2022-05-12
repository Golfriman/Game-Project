#pragma once
#include"TowerState.h"

class RandomEvent : public TowerState
{
	sf::Color white;
	int n = 24;
	std::vector<Button*> buttons;
	sf::Texture* texture;
	std::vector<sf::Text> text;
<<<<<<< Updated upstream
	sf::RectangleShape area;
	void CreateRect();
	void EventEffectSurprise();
	void EventChest();
	void EventMimik();
	void EventSacredAltar();
	void EventBloodyAltar();
	void EventTrap();
	void EventStone();
	void EventBoiler();
	void EventTitle();
	void EventDeadFriend();
	void EventNoiseFighting();
	void EventOffice();
	void EventStrawDoll();
	void EventViewTower();
	void EventHallucinations();
	void EventCorpse();
	void EventReflections();

=======
	sf::Text history;
	std::vector<sf::String> textHistory;
	std::function<void()> next;
	size_t countHistory;
	void createAltarEvent();
>>>>>>> Stashed changes
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
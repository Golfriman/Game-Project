#pragma once
#include"TowerState.h"
#include"Enimies/Enimies.h"

class Battle: public TowerState
{
	int levelGenerate;
	size_t monsterID;
	bool isDelete;
	bool turnPlayer;
	int trigger;
	bool isHover;
	size_t idHoverButton;
	std::vector<Enimies*> enimiesInTheRoom;
	std::vector<Button*> buttons;
	std::list<Items*> dropItems;
	std::list<Button*> dropItemsButton;
	sf::Texture* texture;
	sf::Texture* commandAreaTexture;
	sf::RectangleShape* area;
	sf::Text* text;
	sf::Color* white;
	sf::Sprite wall;
	std::function<void()> commandHero[3];
	std::function<void()> passToMove;

	//HealthBar
	struct HealthBar:sf::Drawable
	{
		Unit* unit;
		sf::Text infoHealth;
		sf::RectangleShape hp;
		sf::RectangleShape max;
		HealthBar(float xPos, float yPos, sf::Font* font, Unit* unit);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};

	std::vector<HealthBar*> healthBars;

	void createUI();
public:
	Battle(System& system, Hero* hero, int level, bool*isLoadSource);
	void update();
	void render();
	void draw();
	void hud();
	void createSource();
	void removeSource();
	~Battle();
};
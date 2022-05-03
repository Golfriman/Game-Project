#pragma once
#include"TowerState.h"
#include"Enimies/Enimies.h"

class Battle: public TowerState
{
	static constexpr int MONSTER_NOT_SELECTED = -1;
	static constexpr int HERO_HEALTHBAR = 0;
	static constexpr int LIGHT_ATTACK = 0;
	static constexpr int HEAVY_ATTACK = 1;
	static constexpr int SPECIAL_ATTACK = 2;
	int levelGenerate;
	size_t monsterID;
	bool isDelete;
	bool turnPlayer;
	int trigger;
	bool isHover;
	size_t idHoverButton;
	bool isHoverEnimie;
	size_t idHoverEnimie;
	std::vector<Enimies*> enimiesInTheRoom;
	std::vector<Button*> enimiesUI;
	std::vector<Button*> buttons;
	std::list<Items*> dropItems;
	std::list<Button*> dropItemsButton;
	sf::Texture* textureButtonUI;
	sf::Texture* textureButtonEnimies;
	sf::Texture* commandAreaTexture;
	sf::Texture* exitRoom;
	sf::RectangleShape* area;
	sf::Text* text;
	sf::Color* white;
	sf::Sprite wall;
	std::function<void()> commandHero[3];
	std::function<void()> passToMove;
	std::function<void()> next;
	Button* exitUI;
	//HealthBar
	struct HealthBar:sf::Drawable
	{
		Unit* unit;
		sf::Text infoHealth;
		sf::RectangleShape hp;
		sf::RectangleShape max;
		HealthBar(float xPos, float yPos, sf::Font* font, Unit* unit);
		void update();
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
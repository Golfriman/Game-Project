#pragma once
#include"State.h"
#include"Settings.h"
#include"./Game/Tower state/Battle.h"
#include"./Game/Tower state/RandomEvent.h"
#include"Game/Tower state/Blacksmith.h"
#include"Game/InventoryScreen.h"
#include"Game/DeathScreen.h"

#include"./Game/Hero.h"
#include<random>

class Engine;

class Game : public State
{
	bool flag;
	System* system;
	Settings* settings;
	std::vector<TowerState*> towerstates;
	std::vector<Button*> buttons;
	static constexpr int ID_INVENTORY = 0;
	InventoryScreen* inventoryScreen;
	bool isDropMenu;
	int idGame;
	int level;
	Hero* hero;
	bool deathScreen = false;
	bool showHUD;
	bool isDelete;
	bool isPressedInventory;
	bool isPressedSettings;
	int lastID;
	std::mt19937* mersenne;
	sf::Texture* texture;
	sf::Texture* textureHero;
	sf::Text* text;
	sf::Text* infoLevel;
	sf::Text* numberLevel;
	sf::Color *white;
	sf::Texture* textureAreaHeroInfo;
	sf::RectangleShape* areaHeroInfo;
	sf::Text* textAreaHeroInfo;
	sf::Text characterHeroText[5];
	void generateLevel(System& system);
	void createUI();

	std::function<void()> clickDropMenu;
	std::function<void()> clickInventory;
	std::function<void()> clickRestart;
	std::function<void()> clickSettings;
	std::function<void()> clickMainMenu;
	
public:
	Game(System& system, bool* isLoadSource);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
	~Game();
};

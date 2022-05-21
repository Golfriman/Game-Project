#pragma once
#include"Tower state/TowerState.h"
#include"Tower state/Enimies/Enimies.h"

class DeathScreen : public TowerState
{
	std::vector<Button*> buttons;
	size_t hoverButton;
	bool isHover;
	sf::Texture* texture;
	sf::Text* text;
	sf::RectangleShape desk;
	bool isDelete;
	sf::Color colorText0 = sf::Color::White;
	sf::Color colorText1 = sf::Color::Red;
	std::function<void()> restartGame;
	std::function<void()> returnMainMenu;
	void createUI();
public:
	DeathScreen(System& system, Hero* hero, bool* isLoadSreen);
	void update()override;
	void render()override;
	void draw()override;
	void hud() override;
	void createSource() override;
	void removeSource() override;
};

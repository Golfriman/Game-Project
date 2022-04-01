#pragma once
#include"State.h"

namespace subState
{
	class SubMenu
	{
	protected:
		sf::Texture* transparency;
		sf::Texture* highlight;
		sf::Font* titleFont;
		sf::Font* normalFont;
		sf::RenderWindow* window;
		Keyboard* keyboard;
		Mouse* mouse;
		Audio* audio;
		int* substate;
		sf::Sound sound;
		bool isPressed;
		bool isHover;
		bool* isLoadSource;
		void playClickEffect();
	public:
		SubMenu();
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void draw() = 0;
		virtual void createSource() = 0;
		virtual void removeSource() = 0;
		virtual ~SubMenu() = default;
	};
	class MainMenu : public SubMenu
	{
	
		sf::Texture* menuWallpaper;
		std::vector<Button*> menu;
		sf::String string[4];
		sf::Text* text;
		sf::Vector2f last;
		int stateNow;
	public:
		MainMenu(System& system, int* substate, bool* isLoadSource);
		void update()override;
		void render()override;
		void draw()override;
		void createSource() override;
		void removeSource() override;
	};
	class ExitMenu : public SubMenu
	{
		std::vector<Button*> exit;
		sf::String* answers;
		sf::Text* text;
		sf::Vector2f last;
		int positionAnswersNow;

	public:
		ExitMenu(System& system, int* substate, bool* isLoadSource);
		void update()override;
		void render()override;
		void draw()override;
		void createSource()override;
		void removeSource()override;
	};
}

class Menu:public State
{
	std::vector<subState::SubMenu*> subMenu;
	int substate;
	bool isDelete;
public:
	Menu(System& system,bool* isLoadSource);
	void createSource();
	void removeSource();
	void update();
	void render();
	void draw();
	~Menu();
};
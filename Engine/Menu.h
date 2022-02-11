#pragma once
#include"State.h"

namespace subState
{
	class SubMenu
	{
	protected:
		sf::Color* transparency;
		sf::Color* highlight;
	public:
		SubMenu() = default;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void draw() = 0;
		virtual void createSource() = 0;
		virtual void deleteSource() = 0;
		virtual ~SubMenu() = default;
	};
	class MainMenu : public SubMenu
	{
		sf::RenderWindow* window;
		Keyboard* keyboard;
		Mouse* mouse;
		int* state;
		sf::Font* titleFont;
		sf::Font* normalFont;
		//Основа
		
		sf::Texture* menuWallpaper;
		std::unordered_map<Coordinate, Button*> menu;
		std::vector<Coordinate> menuPoint;
		sf::String* text;
		Coordinate last;
		bool isPressed;
		int stateNow, stateLast;
		int* substate;
	public:
		MainMenu(System& system, int* substate);
		void update()override;
		void render()override;
		void draw()override;
		void createSource() override;
		void deleteSource() override;
	};
	class ExitMenu : public SubMenu
	{
		sf::RenderWindow* window;
		Keyboard* keyboard;
		Mouse* mouse;
		sf::Font* titleFont;
		sf::Font* normalFont;

		std::unordered_map<Coordinate, Button*> exit;
		std::vector<Coordinate> exitPoint;
		sf::String* answers;
		sf::Text* question;

		int positionAnswersNow;
		bool isPressed;
		int* substate;

	public:
		ExitMenu(System& system, int* substate);
		void update()override;
		void render()override;
		void draw()override;
		void createSource()override;
		void deleteSource()override;
	};
}

class Menu:public State
{
	std::vector<subState::SubMenu*> subMenu;
	int substate;
	bool isDelete;


public:
	Menu(System& system);
	void createSource();
	void removeSource();
	void update();
	void render();
	void draw();
};
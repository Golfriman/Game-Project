#pragma once
#include"State.h"

class Journal : public State
{
	sf::Color* white;
	sf::Text* text;
	sf::RenderWindow *window;
	int* state;
	Keyboard* keyboard;
	Audio* audio;
	Mouse* mouse;
	sf::Font* titleFont;
	sf::Font* normallFont;
	sf::Texture* texture;
	sf::RectangleShape rect;
	std::unordered_map<Coordinate, Button*> buttonJournal;
	std::vector<Coordinate> buttonJournalPoint;
	sf::Color* idle;
	sf::Sound sound;
	bool isDelete;
public:
	Journal(System& system);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};
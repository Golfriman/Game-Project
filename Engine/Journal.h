#pragma once
#include"State.h"

class Journal : public State
{
	sf::Color* white;
	sf::Text* text;
	int* state;
	sf::Texture* texture;
	sf::RectangleShape rect;
	std::vector<Button*> buttonJournal;
	sf::Color* idle;
	sf::Sound sound;
	bool isDelete;
public:
	Journal(System& system, bool* isLoadSource);
	void createSource()override;
	void removeSource()override;
	void update();
	void render();
	void draw();
};
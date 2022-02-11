#pragma once
#include<SFML/Graphics.hpp>
class Window
{
	sf::RenderWindow *window;
	sf::View* camera;
public:
	Window();
	void setWindow();
	bool isOpen();
	sf::RenderWindow* getHandle();
	Window(const Window&) = delete;
	Window& operator==(const Window&) = delete;
	~Window();
};
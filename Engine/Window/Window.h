#pragma once
#include<SFML/Graphics.hpp>
#include<functional>
class Window
{
	sf::RenderWindow *window;
	sf::View* camera;
	bool isFullscreen;
	bool isLimitFPS;
	int height[5], width[5];
	int stateWindow;
public:
	Window();
	void setWindow();
	bool isOpen();
	sf::RenderWindow* getHandle();
	Window(const Window&) = delete;
	Window& operator==(const Window&) = delete;
	void switchFullscreen();
	void switchLimitFPS();
	void leftChangeResolution();
	void rightChangeResolution();
	~Window();
};
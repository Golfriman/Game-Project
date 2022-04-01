#include "Window.h"

Window::Window()
{
	width[0] = 1366;
	height[0] = 768;
	width[1] = 1440;
	height[1] = 900;
	width[2] = 1600;
	height[2] = 900;
	width[3] = 1680;
	height[3] = 1050;
	width[4] = 1920;
	height[4] = 1080;
	window = nullptr;
	camera = nullptr;
}

void Window::setWindow()
{
	stateWindow = 0;
	isFullscreen = false;
	isLimitFPS = true;
	window = new sf::RenderWindow(sf::VideoMode(width[stateWindow], height[stateWindow]), "Window", sf::Style::Close);
	camera = new sf::View(sf::FloatRect(0.f, 0.f, 1920.f, 1080.f));
	window->setView(*camera);
	window->setFramerateLimit(60);
}

bool Window::isOpen()
{
	return window->isOpen();
}

sf::RenderWindow* Window::getHandle()
{
	return window;
}
void Window::switchFullscreen()
{
	if (!isFullscreen)
	{
		window->close();
		window->create(sf::VideoMode::getDesktopMode(), "Window", sf::Style::Fullscreen | sf::Style::Close);
		window->setView(*camera);
		isFullscreen = true;
	}
	else
	{
		sf::Vector2u size = window->getSize();

		window->close();
		window->create(sf::VideoMode(width[stateWindow], height[stateWindow]), "Window", sf::Style::Close);
		window->setView(*camera);
		isFullscreen = false;
	}
	if (isLimitFPS)
	{
		window->setFramerateLimit(60);
		isLimitFPS = true;
	}
	else
	{
		window->setFramerateLimit(1'000);
		isLimitFPS = false;
	}
}

void Window::switchLimitFPS()
{
	if (!isLimitFPS)
	{
		window->setFramerateLimit(60);
		isLimitFPS = true;
	}
	else
	{
		window->setFramerateLimit(1'000);
		isLimitFPS = false;
	}
}

void Window::leftChangeResolution()
{
	if (isFullscreen) return;
	stateWindow = stateWindow + 1 > 4 ? 4 : stateWindow + 1;
	window->setSize(sf::Vector2u(width[stateWindow], height[stateWindow]));
}

void Window::rightChangeResolution()
{
	if (isFullscreen) return;
	stateWindow = stateWindow - 1 < 0 ? 0 : stateWindow - 1;
	window->setSize(sf::Vector2u(width[stateWindow], height[stateWindow]));
}

bool& Window::isFull()
{
	return isFullscreen;
}

bool& Window::isLimit()
{
	return isLimitFPS;
}

Window::~Window()
{
	delete window;
	window = nullptr;
	delete camera;
	camera = nullptr;
}
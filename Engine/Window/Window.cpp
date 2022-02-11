#include "Window.h"

Window::Window()
{
	window = nullptr;
	camera = nullptr;
}

void Window::setWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(1024, 720), "Window"/*, sf::Style::Fullscreen*/);
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

Window::~Window()
{
	if (window != nullptr)
	{
		delete window;
		window = nullptr;
	}
}
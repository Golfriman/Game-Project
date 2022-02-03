#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "window");

	window.setFramerateLimit(60);
	sf::Event event;
	while (window.isOpen())
	{
		window.clear();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		window.display();
	}
	return 0;
}
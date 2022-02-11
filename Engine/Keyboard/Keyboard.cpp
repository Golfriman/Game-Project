#include "Keyboard.h"

Keyboard::Keyboard()
{
	
	key.left = sf::Keyboard::A;
	key.right = sf::Keyboard::D;
	key.down = sf::Keyboard::S;
	key.up = sf::Keyboard::W;
	key.inventory = sf::Keyboard::I;
	key.hide = sf::Keyboard::H;
	key.escape = sf::Keyboard::Escape;
	key.accept = sf::Keyboard::Enter;

}

Keyboard::Key& Keyboard::getConfig()
{
	return key;
}

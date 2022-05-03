#include "BlacksmithMenu.h"

void BlacksmithMenu::createUI()
{
	insertButton(0, menuButton, 1500, 201, 359, 100, &textureButton[0]);
	setText("Talk about tower", textButton[0], normallFont, 1529, 229, *white, 36);
	menuButton[0]->setOnClick(pressToMove);

	insertButton(1, menuButton, 1500, 321, 359, 100, &textureButton[0]);
	setText("Modification arms", textButton[0], normallFont, 1515,349, *white, 36);
	menuButton[1]->setOnClick(pressToMove);

	insertButton(2, menuButton, 1500, 440, 359, 100, &textureButton[0]);
	setText("Get away", textButton[0], normallFont, 1583, 469, *white, 36);
	menuButton[2]->setOnClick(pressToMove);

	insertButton(3, menuButton, 394, 240, 131, 45, &textureButton[0]);
	setText("Let's go", textButton[0], normallFont, 416, 248, *white, 36);
	menuButton[3]->setOnClick(pressToMove);

}

BlacksmithMenu::BlacksmithMenu(System& system, Hero* hero, bool* isLoadSource)
{
	init(system, hero, isLoadSource);

}

void BlacksmithMenu::update()
{
	if (event->type == sf::Event::MouseMoved)
	{
		//логика наведени€ мыши
	}
	else if (event->type == sf::Event::MouseButtonPressed)
	{
		if (event->key.code == sf::Mouse::Left)
		{
			//логика при нажатии
		}
	}
	


}

void BlacksmithMenu::render()
{
	
}

void BlacksmithMenu::draw()
{
	return;
}

void BlacksmithMenu::hud()
{
	//отрисовка текста и кнопок (get away)
	/*
	* handle->draw(button);  отрисовка кнопки на экран
	* 
	* 
	*/
}

void BlacksmithMenu::createSource()
{
	textureButton = new sf::Texture[1];
	white = new sf::Color(sf::Color::White);
	commandAreaTexture = new sf::Texture;
	textButton = new sf::Text[1];
	loadTexture("resources//Image//Textures//greenbackground.png", &textureButton[0]);
	/*loadTexture("", commandAreaTexture);
	commandAreaTexture->setSmooth(true);
	area = new sf::RectangleShape;
	area->setSize(sf::Vector2f(935.f, 133.f));
	area->setPosition(494, 898);
	area->setTexture(commandAreaTexture, true);*/
	createUI();

}

void BlacksmithMenu::removeSource()
{
	deleteArrayObject(textureButton);
	deleteArrayObject(textButton);
	/*deleteObject(white);
	deleteObject(commandAreaTexture);
	deleteObject(area);*/

}

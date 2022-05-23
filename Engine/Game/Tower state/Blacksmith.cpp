#include"Blacksmith.h"
#include"BlacksmithEvent/BlacksmithEvent.h"
#include"BlacksmithEvent/Dialog.h"
#include"BlacksmithEvent/UpgradeWeapon.h"
#include"BlacksmithEvent/Farewell.h"
#include"BlacksmithEvent/BlacksmithMenu.h"


BlackSmith::BlackSmith(System& system, Hero* hero, bool *isLoadSource)
{
	init(system, hero, isLoadSource);
	bEvents =
	{
		std::make_pair(ID_MENU_B, new BlacksmithMenu(system, hero, isLoadSource)),
		std::make_pair(ID_TALK_B, new Dialog(system, hero, isLoadSource)),
		std::make_pair(ID_MOD_B, new UpgradeWeapon(system, hero, isLoadSource)),
		std::make_pair(ID_EXIT_B, new Farewell(system, hero, isLoadSource))
	};

	
	stateBlack = ID_MENU_B;

	bEvents[stateBlack]->createSource();
}

void BlackSmith::update()
{
	try 
	{
		bEvents[stateBlack]->update();
	}
	catch (int id) 
	{
		if (id == ID_NEXT)
		{
			throw ID_NEXT;
		}
		bEvents[stateBlack]->removeSource();
		stateBlack = id;
		bEvents[stateBlack]->createSource();
	}
}	

void BlackSmith::render()
{
	bEvents[stateBlack]->render();

}

void BlackSmith::draw()
{
	handle->draw(*wallpaper);
	bEvents[stateBlack]->draw();
}

void BlackSmith::hud()
{
	bEvents[stateBlack]->hud();
}

void BlackSmith::createSource()
{
	t_wallpaper = new sf::Texture;
	loadTexture("resources//Image//Textures//Blacksmith.png", t_wallpaper);
	wallpaper = new sf::RectangleShape(sf::Vector2f(1920,1080));
	wallpaper->setPosition(0, 0);
	wallpaper->setTexture(t_wallpaper, true);



	//фон, звук
}

void BlackSmith::removeSource()
{
	deleteObject(t_wallpaper);
	deleteObject(wallpaper);
	//фон, звук
}

BlackSmith::~BlackSmith()
{
	for (auto& blacksmith : bEvents)
	{
		deleteObject(blacksmith.second);
	}
	bEvents.clear();
}

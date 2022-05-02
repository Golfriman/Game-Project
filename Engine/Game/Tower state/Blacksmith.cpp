#include"Blacksmith.h"
#include"BlacksmithEvent/BlacksmithEvent.h"
#include"BlacksmithEvent/Dialog.h"
#include"BlacksmithEvent/UpgradeWeapon.h"
#include"BlacksmithEvent/Farewell.h"

BlackSmith::BlackSmith(System& system, Hero* hero, bool *isLoadSource)
{
	init(system, hero, isLoadSource);
	bEvents.resize(3);
	bEvents[0] = new Dialog(system, hero, isLoadSource);
	bEvents[1] = new UpgradeWeapon(system, hero, isLoadSource);
	bEvents[2] = new Farewell(system, hero, isLoadSource);
	stateBlack = 0;
}

void BlackSmith::update()
{
	try 
	{
		bEvents[stateBlack]->update();
	}
	catch (size_t id) 
	{
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
	bEvents[stateBlack]->draw();
}

void BlackSmith::hud()
{
	return;
}

void BlackSmith::createSource()
{
	//фон, звук
}

void BlackSmith::removeSource()
{
	//фон, звук
}

BlackSmith::~BlackSmith()
{
	for (auto& blacksmith : bEvents)
	{
		deleteObject(blacksmith);
	}
	bEvents.clear();
}

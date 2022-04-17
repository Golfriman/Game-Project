#include"Blacksmith.h"
#include"BlacksmithEvent/BlacksmithEvent.h"
#include"BlacksmithEvent/Dialog.h"
#include"BlacksmithEvent/UpgradeWeapon.h"
#include"BlacksmithEvent/Farewell.h"

BlackSmith::BlackSmith(System& system, Hero* hero, bool *isLoadSource)
{
	init(system, hero, isLoadSource);
	bEvents.resize(3);
	bEvents[0] = new Dialog();
	bEvents[1] = new UpgradeWeapon();
	bEvents[2] = new Farewell();
}

void BlackSmith::update()
{
}

void BlackSmith::render()
{
}

void BlackSmith::draw()
{
}

void BlackSmith::hud()
{
	/*..*/
}

void BlackSmith::createSource()
{
}

void BlackSmith::removeSource()
{
}

BlackSmith::~BlackSmith()
{
	for (auto& blacksmith : bEvents)
	{
		deleteObject(blacksmith);
	}
	bEvents.clear();
}

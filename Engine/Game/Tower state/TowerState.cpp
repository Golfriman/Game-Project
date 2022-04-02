#include "TowerState.h"

void TowerState::init(System& system, Hero* hero)
{
	handle = system.getHandle();
	mouse = system.getMouse();
	keyboard = &system.getKeyboard();
	audio = &system.getAudio();
	titleFont = system.getTitleFont();
	normallFont = system.getNormalFont();
	this->hero = hero;
}

TowerState::TowerState()
{
	hero = nullptr;
	handle = nullptr;
	audio = nullptr;
	keyboard = nullptr;
	mouse = nullptr;
	titleFont = nullptr;
	normallFont = nullptr;
}

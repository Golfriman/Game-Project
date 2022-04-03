#include "TowerState.h"

void TowerState::init(System& system, Hero* hero)
{
	this->handle = system.getHandle();
	this->mouse = system.getMouse();
	this->keyboard = &system.getKeyboard();
	this->audio = &system.getAudio();
	this->titleFont = system.getTitleFont();
	this->normallFont = system.getNormalFont();
	this->hero = hero;
}

TowerState::TowerState()
{
	hero = nullptr;
	handle = nullptr;
	audio = nullptr;
	keyboard = nullptr;
	mouse = nullptr;
}

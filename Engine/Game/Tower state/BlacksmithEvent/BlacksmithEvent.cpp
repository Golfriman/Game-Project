#include "BlacksmithEvent.h"

void BlacksmithEvent::init(System& system, Hero* hero, bool* isLoadSource)
{
	this->handle = system.getHandle();
	this->mouse = system.getMouse();
	this->keyboard = &system.getKeyboard();
	this->audio = &system.getAudio();
	this->titleFont = system.getTitleFont();
	this->normallFont = system.getNormalFont();
	this->hero = hero;
	this->event = system.getEvent();
	this->isLoadSource = isLoadSource;
}

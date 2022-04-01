#include "State.h"

void State::initSystemComponent(System& system)
{
	handle = system.getHandle();
	mouse = system.getMouse();
	keyboard = &system.getKeyboard();
	audio = &system.getAudio();
	titleFont = system.getTitleFont();
	normallFont = system.getNormalFont();
}

State::State()
{
	this->window = nullptr;
	this->audio = nullptr;
	this->mouse = nullptr;
	this->keyboard = nullptr;
	this->handle = nullptr;
}

#include "State.h"

void State::initSystemComponent(System& system)
{
	window = &system.getWindow();
	handle = system.getHandle();
	mouse = system.getMouse();
	keyboard = &system.getKeyboard();
	audio = &system.getAudio();
	titleFont = system.getTitleFont();
	normallFont = system.getNormalFont();
	event = system.getEvent();
}

State::State()
{
	this->window = nullptr;
	this->audio = nullptr;
	this->mouse = nullptr;
	this->keyboard = nullptr;
	this->handle = nullptr;
	this->event = nullptr;
}

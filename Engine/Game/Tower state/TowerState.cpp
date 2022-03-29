#include "TowerState.h"

void TowerState::initSystemComponent(System& system)
{
	handle = system.getHandle();
	mouse = system.getMouse();
	state = &system.getState();
	keyboard = &system.getKeyboard();
	audio = &system.getAudio();
	titleFont = system.getTitleFont();
	normallFont = system.getNormalFont();
}

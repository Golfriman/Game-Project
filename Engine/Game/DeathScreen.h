#pragma once
#include"Tower state/TowerState.h"
#include"Tower state/Enimies/Enimies.h"

class DeathScreen : public TowerState
{
	std::vector<Button*> buttons;
};

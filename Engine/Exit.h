#pragma once
#include"State.h"

class Exit : public State
{
public:
	Exit(System& system, bool* isLoadSource);
	void removeSource()override;
	void createSource()override;
	void update();
	void render();
	void draw();
};
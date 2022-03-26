#pragma once
#include"TowerState.h"
#include<vector>
#include"BlacksmithEvent/BlacksmithEvent.h"

class BlackSmith : public TowerState
{
	std::vector<BlacksmithEvent*> events;
public:
	void update() = 0;
	void render() = 0;
	void draw() = 0;
	void createSource() = 0;
	void removeSource() = 0;
	~BlackSmith() = default;
};

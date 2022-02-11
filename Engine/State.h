#pragma once
#include"Global/Support function.h"
#include"System.h"

class State
{
public:
	State() = default;
	virtual void createSource() = 0;
	virtual void removeSource() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual ~State() = default;
};

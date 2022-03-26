#pragma once
#include"../../Unit.h"
#include"../../Items/Items.h"
#include"Intellect.h"
class Enimies: public Unit
{
protected:
	Items* items;
	Intellect* intellect;
	void dropItem();
public:
	virtual void execute() = 0;
	void create();
	Items* kill();

};

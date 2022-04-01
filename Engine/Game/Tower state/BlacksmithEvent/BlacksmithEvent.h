#pragma once
class BlacksmithEvent
{

public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void draw() = 0;
	virtual void hud() = 0;
	virtual void createSource() = 0;
	virtual void removeSource() = 0;
	virtual ~BlacksmithEvent() = default;
};
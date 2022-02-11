#include"Engine/Engine.h"

int main()
{
	Engine engine;
	while (engine.windowIsOpen())
	{
		engine.update();
		engine.render();
		engine.draw();
	}
	return 0;
}
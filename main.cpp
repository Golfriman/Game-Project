#include"Engine/Engine.h"
//��������� �������������� �� ������������� enum
#pragma warning(suppress: 26812)
struct Leaks
{
	~Leaks()
	{
		_CrtDumpMemoryLeaks() ? std::cout << "leaks" : std::cout << '\0';
		
	}
}check;
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
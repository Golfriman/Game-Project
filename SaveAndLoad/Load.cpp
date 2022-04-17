#include "Load.h"

void  LoadFile::loadFile()
{

	std::ifstream loadSet("resources//Save//Settings.txt");

	if (!loadSet.is_open())
	{
		std::cerr << "Settings.txt could not be opened!\n";
		return;
	}
	else
	{
		loadSet >> loadJ;
	}

	loadSet.close();
}

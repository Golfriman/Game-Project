#include <Load.h>

void  LoadFile::loadFile()
{

	std::ifstream loadSet("Settings.txt");

	if (!loadSet.is_open())
	{

		std::cerr << "Settings.txt could not be opened!\n";
		exit(1);
	}
	else loadSet >> serialized;

	loadSet.close();
}

void LoadFile::outNote(string key, T1 object)
{
	object = loadJ[key].get<T1>();
}
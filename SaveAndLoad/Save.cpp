#include <Save.h>


void Save::addNote(string key, T object)
{
	saveJ[key] = object;
}

void Save::saveFile()
{

	std::string serializedString = saveJ.dump();

	std::ofstream saveSet;

	saveSet.open("Settings.txt");

	if (!saveSet.is_open())
	{

		std::cerr << "Settings.txt could not be opened for writing!\n";
		exit(1);
	}

	saveSet << serializedString;
	saveSet.close();
}
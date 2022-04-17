#include "Save.h"

void Save::saveFile()
{

	std::string serializedString = saveJ.dump();

	std::ofstream saveSet;

	saveSet.open("resources//Save//Settings.txt");

	if (!saveSet.is_open())
	{

		std::cerr << "Settings.txt could not be opened for writing!\n";
		exit(1);
	}

	saveSet << serializedString;
	saveSet.close();
}
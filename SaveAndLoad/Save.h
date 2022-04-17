#pragma once
#include"nlohmann/json.hpp"
#include<fstream>
#include <string>
#include <cstdlib>
#include <typeinfo>

class Save
{
private:
	nlohmann::json saveJ{};
public:

	template <typename T>

	void addNote(string key, T object);

	void saveFile();

};
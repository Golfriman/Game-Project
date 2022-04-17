#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

class Save
{
private:
	nlohmann::json saveJ{};
public:

	template <typename T>

	void addNote(std::string key, T& object)
	{
		saveJ[key] = object;
	}

	void saveFile();

};
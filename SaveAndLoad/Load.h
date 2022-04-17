#pragma once
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>

class LoadFile
{
	nlohmann::json loadJ;
public:


	void loadFile();

	template <typename T1>

	void outNote(std::string key, T1& object)
	{
		if (!loadJ.empty())
		{
			object = loadJ[key].get<T1>();
		}
	}
};
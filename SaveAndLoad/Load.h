#pragma once
#include"nlohmann/json.hpp"
#include<fstream>
#include<iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>

class LoadFile
{

	std::string serialized;
public:


	void loadFile();


	nlohmann::json loadJ = nlohmann::json::parse(serialized);

	template <typename T1>

	void outNote(string key, T1 object);

};
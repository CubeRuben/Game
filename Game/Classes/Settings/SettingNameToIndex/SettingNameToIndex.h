#pragma once

#include <string>

class SettingNameToIndex
{
public:
	std::string name;
	int index;

	SettingNameToIndex();
	SettingNameToIndex(std::string name, int index);
};
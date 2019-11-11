#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "SettingNameToIndex/SettingNameToIndex.h"

class Settings
{
private:
	int* settingsInt;
	SettingNameToIndex settingNameToIndex[2] =
	{
		SettingNameToIndex("window_width", SettingsVars::WINDOW_WIDTH),
		SettingNameToIndex("window_height", SettingsVars::WINDOW_HEIGHT)
	};
public:
	enum SettingsVars 
	{
		WINDOW_WIDTH,
		WINDOW_HEIGHT
	};

	Settings();

	int getSettings(SettingsVars setting);
};
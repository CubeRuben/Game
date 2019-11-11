#include "Settings.h"

Settings::Settings() 
{
	settingsInt = new int[2];

	settingsInt[0] = 1366;
	settingsInt[1] = 768;

	//std::fstream settingsFile;

	//settingsFile.open("settings.txt");

	/*if (!settingsFile) 
	{
		std::cout << "ERROR: Settings file not found" << std::endl;
	} 
	else
	{
		/*std::string data;
		while (std::getline(data, settingsFile))
		{

		}
	}*/
}


int Settings::getSettings(Settings::SettingsVars setting) 
{
	return settingsInt[setting];
}
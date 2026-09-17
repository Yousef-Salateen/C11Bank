#pragma once

#include "clsString.h"
#include <fstream>
#include <vector>

class clsFiles
{
public:
	static std::vector <std::string> LoadDataFromFile(std::fstream& File)
	{
		std::vector <std::string> vData;
		if (File.is_open())
		{
			std::string Line;
			while (getline(File, Line))
			{
				vData.push_back(Line);
			}
		}
		return vData;
	}

	static std::vector<std::string> SeperateLineData(const std::string& Line, const std::string& Seperator = "#//#")
	{
		std::vector<std::string> vData = clsString::Split(Line, Seperator);
		return vData;
	}

	static void SaveDataToFile(std::fstream& File, const std::vector<std::string>& vData)
	{
		if (File.is_open())
		{
			for (const std::string& Line : vData)
			{
				File << Line << std::endl;
			}
		}
	}

	static void AddLineToFile(std::fstream& File, const std::string& Line)
	{
		if (File.is_open())
		{
			File << Line << std::endl;
		}
	}

};
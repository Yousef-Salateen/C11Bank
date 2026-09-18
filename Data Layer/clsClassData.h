#pragma once

#include <fstream>
#include <vector>
#include "../External Libs/clsFiles.h"

template <typename clsDataManager, typename clsClass>
class clsClassData
{
public:
	static std::vector<clsClass*> LoadDataFromFile(const std::string& FileName)
	{
		std::vector<clsClass*> vObjects;
		std::fstream File(FileName, std::ios::in);

		std::vector<std::string> vData = clsFiles::LoadDataFromFile(File);
		vObjects.reserve(vData.size());

		for (const std::string& Line : vData)
		{
			vObjects.emplace_back(new clsClass(clsDataManager::ConvertLineToObject(Line)));
		}

		File.close();

		return vObjects;
	}

	static void SaveDataToFile(const std::string& FileName, const std::vector<clsClass*>& vObjects)
	{
		std::fstream File(FileName, std::ios::out);
		std::vector <std::string> vData;
		vData.reserve(vObjects.size());

		for (const clsClass* Object : vObjects)
		{
			if (Object && !Object->MarkedForDelete())
			{
				vData.emplace_back(clsDataManager::ConvertObjectToLine(Object));
			}
		}

		clsFiles::SaveDataToFile(File, vData);
		File.close();
	}
};


#pragma once

#include "clsClassData.h"
#include <string>
#include "../Middle Layer/clsLoginInfo.h"

class clsLoginData :
	public clsClassData<clsLoginData, clsLoginInfo>
{
private:
	inline static const std::string _LoginLogFile = "LoginLogs.txt";
	inline static const std::string _Seperator = "#//#";

public:
	static clsLoginInfo ConvertLineToObject(const std::string& Line)
	{
		std::vector<std::string> vLoginData = clsFiles::SeperateLineData(Line, _Seperator);

		if (vLoginData.empty())
		{
			return clsLoginInfo::EmptyObject();
		}

		return clsLoginInfo(vLoginData.at(0), vLoginData.at(1), vLoginData.at(2), std::stoi(vLoginData.at(3)));
	}

	static std::string ConvertObjectToLine(const clsLoginInfo* Object)
	{
		return Object->DateLine() + _Seperator + Object->Username() + _Seperator + Object->Password() + _Seperator + std::to_string(Object->Permissions());
	}

	friend class clsData;
};


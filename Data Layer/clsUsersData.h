#pragma once

#include "../External Libs/clsFiles.h"
#include "../Middle Layer/clsUser.h"
#include <fstream>
#include <vector>
#include "clsClassData.h"

//This class responsible for loading and saving users data to and from a file
//This class is irresponsible for what happens to the data after it is loaded from the file, and what happens to the data before it is saved to the file
//After data is loaded from the file, it is the responsibility of the caller to manage the data
//and before saving the data to the file, it is the responsibility of the caller to prepare the data for saving
class clsUsersData
	: public clsClassData<clsUsersData, clsUser>
{
	inline static const std::string _UsersFileName = "Users.txt";
	inline static const std::string _Seperator = "#//#";

	enum enInfoPos : char { _FirstName = 0, _LastName, _Email, _Phone, _Username, _Password, _Permissions };
public:

	static clsUser ConvertLineToObject(const std::string& Line)
	{
		std::vector<std::string> vUserData = clsFiles::SeperateLineData(Line, _Seperator);

		if (vUserData.empty())
		{
			return clsUser::EmptyObject();
		}

		return clsUser(vUserData.at(enInfoPos::_FirstName), vUserData.at(enInfoPos::_LastName), vUserData.at(enInfoPos::_Email),
			vUserData.at(enInfoPos::_Phone), vUserData.at(enInfoPos::_Username), vUserData.at(enInfoPos::_Password),
			stoi(vUserData.at(enInfoPos::_Permissions)), clsUser::enMode::_UpdateMode);
	}

	static std::string ConvertObjectToLine(const clsUser* Object)
	{
		return Object->FirstName() + _Seperator + Object->LastName() + _Seperator + Object->Email() + _Seperator + Object->Phone() + _Seperator +
			Object->Username() + _Seperator + Object->Password() + _Seperator + std::to_string(Object->Permissions());
	}

	friend class clsData;
};
